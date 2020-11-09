#include "stdafx.h"
#include "Collider.h"

Collider::Collider()
	: bDrawColliderColor(false)
{
	shader = new Shader(L"Bounding.fx");

	Vertex vertices[5];
	vertices[0].Position = Vector3(-0.5f, -0.5f, 0.0f);
	vertices[1].Position = Vector3(-0.5f, +0.5f, 0.0f);
	vertices[2].Position = Vector3(+0.5f, +0.5f, 0.0f);
	vertices[3].Position = Vector3(+0.5f, -0.5f, 0.0f);
	vertices[4].Position = Vector3(-0.5f, -0.5f, 0.0f);

	// Create VertexBuffer
	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
		desc.Usage = D3D11_USAGE_DEFAULT;
		desc.ByteWidth = sizeof(Vertex) * 5;
		desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		D3D11_SUBRESOURCE_DATA data;
		ZeroMemory(&data, sizeof(D3D11_SUBRESOURCE_DATA));
		data.pSysMem = vertices;
	
		HRESULT hr = Device->CreateBuffer(&desc, &data, &vertexBuffer);
		assert(SUCCEEDED(hr));
	}

	D3DXMatrixIdentity(&world);
	sWorld = shader->AsMatrix("World");
	sView = shader->AsMatrix("View");
	sProjection = shader->AsMatrix("Projection");
	sColor = shader->AsVector("LineColor");

	initLineColor = Color(0, 1, 0, 1);
	collidedColor = Color(1, 0, 0, 1);
}

Collider::~Collider()
{
	SAFE_RELEASE(vertexBuffer);
	SAFE_DELETE(shader);
}

void Collider::Update(Matrix & V, Matrix & P)
{
	sWorld->SetMatrix(world);
	sView->SetMatrix(V);
	sProjection->SetMatrix(P);
}

void Collider::Render()
{
	UINT stride = sizeof(Vertex);
	UINT offset = 0;

	DeviceContext->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
	DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);

	sColor->SetFloatVector(bDrawColliderColor ? collidedColor : initLineColor);

	shader->Draw(0, 0, 5);
}

void Collider::World(Matrix & _world)
{
	world = _world;
}

void Collider::World(Matrix & _world, Vector2 scale)
{
	world = _world;
	world._11 = world._11 * scale.x;
	world._22 = world._22 * scale.y;
	/*
	Vector2 s = Vector2(world._11, world._22);
	s.x *= scale.x;
	s.y *= scale.y;	
	Vector3 S;
	Vector3 T;
	Vector3 R;
	D3DXQUATERNION rotation;
	Matrix m;
	D3DXMatrixDecompose(&S, &rotation, &T, &m);

	D3DXMATRIX temp;
	D3DXMatrixRotationQuaternion(&temp, &rotation);
	R.x = asin(-temp._32);
	R.y = atan2(temp._31, temp._33);
	R.z = atan2(temp._12, temp._22);
	*/
}

void Collider::Position(Vector2 vec)
{
	world._41 = vec.x;
	world._42 = vec.y;
}

/*
bool Collider::Aabb(Matrix & world, Vector2& position)
{
	Vector2 position1 = Vector2(fabsf(world._41), fabsf(world._42));
	Vector2 position2 = position;

	Vector2 distance;
	distance.x = fabsf(position1.x - position2.x);
	distance.y = fabsf(position1.y - position2.y);

	Vector2 halfSize;
	halfSize = Vector2(fabsf(world._11), fabsf(world._22)) * 0.5f;

	if (distance.x > halfSize.x) return false;
	if (distance.y > halfSize.y) return false;

	return true;
}
*/

bool Collider::Aabb(Matrix & world1, Matrix & world2)
{
	Vector2 position1 = Vector2(world1._41, world1._42);
	Vector2 position2 = Vector2(world2._41, world2._42);

	Vector2 distance;
	distance.x = fabsf(position1.x - position2.x);
	distance.y = fabsf(position1.y - position2.y);

	Vector2 halfSize1, halfSize2;
	halfSize1 = Vector2(fabsf(world1._11), fabsf(world1._22)) * 0.5f;
	halfSize2 = Vector2(fabsf(world2._11), fabsf(world2._22)) * 0.5f;

	if (distance.x > halfSize1.x + halfSize2.x) return false;
	if (distance.y > halfSize1.y + halfSize2.y) return false;

	return true;
}
