#include "stdafx.h"
#include "Sprite.h"

Sprite::Sprite(wstring texture_file, wstring shader_file)
{
	Initialize(texture_file, shader_file, 0, 0, 0, 0);
}

Sprite::Sprite(wstring texture_file, wstring shader_file, float end_x, float end_y)
{
	Initialize(texture_file, shader_file, 0, 0, end_x, end_y);
}

Sprite::Sprite(wstring texture_file, wstring shader_file, float start_x, float start_y, float end_x, float end_y)
{
	Initialize(texture_file, shader_file, start_x, start_y, end_x, end_y);
}

void Sprite::Initialize(wstring _texture_file, wstring _shader_file, float start_x, float start_y, float end_x, float end_y)
{
	texture_file = L"./_Textures/" + _texture_file;

	shader = make_unique<Shader>(_shader_file);

	srv = Sprites::Load(texture_file);
	shader->AsShaderResource("DiffuseMap")->SetResource(srv);

	D3DX11_IMAGE_INFO info;
	HRESULT hr = D3DX11GetImageInfoFromFile(texture_file.c_str(), nullptr, &info, nullptr);
	assert(SUCCEEDED(hr));

	// UV ÁÂÇ¥
	float uv_start_x = (start_x > 0) ? start_x / (float)info.Width : 0.0f;
	float uv_start_y = (start_y > 0) ? start_y / (float)info.Height : 0.0f;
	float uv_end_x = (end_x > 0) ? end_x / (float)info.Width : 1.0f;
	float uv_end_y = (end_y > 0) ? end_y / (float)info.Height : 1.0f;

	Vertex vertices[4];
	vertices[0].Position = Vector3(-0.5f, -0.5f, 0.0f);
	vertices[1].Position = Vector3(-0.5f, +0.5f, 0.0f);
	vertices[2].Position = Vector3(+0.5f, -0.5f, 0.0f);
	vertices[3].Position = Vector3(+0.5f, +0.5f, 0.0f);

	vertices[0].Uv = Vector2(uv_start_x, uv_end_y);
	vertices[1].Uv = Vector2(uv_start_x, uv_start_y);
	vertices[2].Uv = Vector2(uv_end_x, uv_end_y);
	vertices[3].Uv = Vector2(uv_end_x, uv_start_y);

	// texture Å©±â
	float texture_width = end_x - start_x;
	float texture_height = end_y - start_y;
	texture_size = Vector2(texture_width, texture_height);
	
	// Default World
	scale = Vector2(1.0f, 1.0f);
	position = Vector2(0, 0);
	rotation = Vector3(0, 0, 0);
	D3DXMatrixIdentity(&world);
	
	sWorld = shader->AsMatrix("World");
	sView = shader->AsMatrix("View");
	sProjection = shader->AsMatrix("Projection");
	UpdateWorld();

	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
		desc.Usage = D3D11_USAGE_DEFAULT;
		desc.ByteWidth = sizeof(Vertex) * 4;
		desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		D3D11_SUBRESOURCE_DATA data;
		ZeroMemory(&data, sizeof(D3D11_SUBRESOURCE_DATA));
		data.pSysMem = vertices;
		HRESULT hr = Device->CreateBuffer(&desc, &data, &vertexBuffer);
		assert(SUCCEEDED(hr));
	}

	UINT indices[] = { 0, 1, 2, 2, 1, 3 };
	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
		desc.Usage = D3D11_USAGE_IMMUTABLE;
		desc.ByteWidth = sizeof(UINT) * 6;
		desc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		D3D11_SUBRESOURCE_DATA data;
		ZeroMemory(&data, sizeof(D3D11_SUBRESOURCE_DATA));
		data.pSysMem = indices;
		HRESULT hr = Device->CreateBuffer(&desc, &data, &indexBuffer);
		assert(SUCCEEDED(hr));
	}
}

Sprite::~Sprite()
{
	//Sprites::Remove(textureFile);
}

void Sprite::Update(Matrix& V, Matrix& P)
{
	sView->SetMatrix(V);
	sProjection->SetMatrix(P);
}

void Sprite::Render()
{
	UINT stride = sizeof(Vertex);
	UINT offset = 0;
	DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	DeviceContext->IASetVertexBuffers(0, 1, vertexBuffer.GetAddressOf(), &stride, &offset);
	DeviceContext->IASetIndexBuffer(indexBuffer.Get(), DXGI_FORMAT_R32_UINT, 0);
	shader->DrawIndexed(0, 0, 6);
}

void Sprite::Position(float x, float y)
{
	Position(Vector2(x, y));
}

void Sprite::Position(Vector2 & vec)
{
	position = vec;

	UpdateWorld();
}

Vector2 Sprite::Position() const
{
	return position;
}

void Sprite::Scale(float x, float y)
{
	Scale(Vector2(x, y));
}

void Sprite::Scale(Vector2 & vec)
{
	scale = vec;

	UpdateWorld();
}

Vector2 Sprite::Scale() const
{
	return scale;
}

void Sprite::Rotation(float x, float y, float z)
{
	Rotation(Vector3(x, y, z));
}

void Sprite::Rotation(Vector3 & vec)
{
	rotation = vec;

	UpdateWorld();
}

Vector3 Sprite::Rotation() const
{
	return rotation;
}

void Sprite::RotationDegree(float x, float y, float z)
{
	RotationDegree(Vector3(x, y, z));
}

void Sprite::RotationDegree(Vector3 & vec)
{
	vec.x = Math::ToRadian(vec.x);
	vec.y = Math::ToRadian(vec.y);
	vec.z = Math::ToRadian(vec.z);

	Rotation(vec);
}

Vector3 Sprite::RotationDegree() const
{
	Vector3 vec;
	vec.x = Math::ToDegree(rotation.x);
	vec.y = Math::ToDegree(rotation.y);
	vec.z = Math::ToDegree(rotation.z);
	
	return vec;
}

Vector2 Sprite::TextureSize() const
{
	return texture_size;
}

Matrix& Sprite::World()
{
	return world;
}

void Sprite::SetWorld(Matrix & _world)
{
	world = _world;
}

float Sprite::ForwardVector()
{
	Matrix R;
	D3DXMatrixRotationY(&R, rotation.y);
	return R._11;
}

void Sprite::UpdateWorld()
{
	// aline all object
	Matrix S, R, T;
	D3DXMatrixScaling(&S, texture_size.x * scale.x, texture_size.y * scale.y, 1.0f);
	//D3DXMatrixRotationY(&R, rotation.y);
	D3DXMatrixRotationYawPitchRoll(&R, rotation.y, rotation.x, rotation.z);
	D3DXMatrixTranslation(&T, position.x , position.y + texture_size.y * 0.5f, 0.0f);
	world = S * R * T;
	sWorld->SetMatrix(world);
}

map<wstring, Sprites::SpriteDesc> Sprites::sprite_map;

ID3D11ShaderResourceView * Sprites::Load(wstring file)
{
	if (sprite_map.count(file) > 0)
	{
		sprite_map[file].RefCount++;
		return sprite_map[file].SRV.Get();
	}

	ID3D11ShaderResourceView* srv;
	HRESULT hr = D3DX11CreateShaderResourceViewFromFile
	(
		Device.Get(), file.c_str(), nullptr, nullptr, &srv, nullptr
	);
	assert(SUCCEEDED(hr));
	
	SpriteDesc desc;
	desc.RefCount++;
	desc.SRV = srv;

	sprite_map[file] = desc;

	return desc.SRV.Get();
}

void Sprites::Remove(wstring file)
{
	UINT count = sprite_map.count(file);
	assert(count > 0);

	sprite_map[file].RefCount--;

	if (sprite_map[file].RefCount < 1)
	{
		//SAFE_RELEASE(spriteMap[file].SRV);
		sprite_map.erase(file);
	}
}
