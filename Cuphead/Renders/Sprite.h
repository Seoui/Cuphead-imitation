#pragma once

class Sprite
{
public:
	Sprite(wstring texture_file, wstring shader_file);
	Sprite(wstring texture_file, wstring shaderFile, float end_x, float end_y);
	Sprite(wstring texture_file, wstring shaderFile, float start_x, float start_y, float end_x, float end_y);
	~Sprite();

	void Update(Matrix& V, Matrix& P);
	void Render();

	void Position(float x, float y);
	void Position(Vector2& vec);
	Vector2 Position() const;
	void Scale(float x, float y);
	void Scale(Vector2& vec);
	Vector2 Scale() const;
	void Rotation(float x, float y, float z);
	void Rotation(Vector3& vec);
	Vector3 Rotation() const;
	void RotationDegree(float x, float y, float z);
	void RotationDegree(Vector3& vec);
	Vector3 RotationDegree() const;

	Matrix& World();
	void SetWorld(Matrix& world);
	Vector2 TextureSize() const;
	float ForwardVector();

private:
	void UpdateWorld();
	void Initialize(wstring textureFile, wstring shaderFile, float startX, float startY, float endX, float endY);

private:
	struct Vertex
	{
		Vector3 Position;
		Vector2 Uv;
	};

private:
	unique_ptr<Shader> shader;
	Microsoft::WRL::ComPtr<ID3D11Buffer> vertexBuffer;
	Microsoft::WRL::ComPtr<ID3D11Buffer> indexBuffer;
	Microsoft::WRL::ComPtr<ID3DX11EffectMatrixVariable> sWorld;
	//ID3DX11EffectMatrixVariable* sWorld;
	ID3DX11EffectMatrixVariable* sProjection;
	ID3DX11EffectMatrixVariable* sView;
	ID3D11ShaderResourceView* srv;

	Matrix world;
	Vector2 position;
	Vector2 scale;
	Vector3 rotation;
	Vector2 texture_size;
	wstring texture_file;
	float forward_vector;
};

class Sprites
{
private:
	friend class Sprite;

private:
	static ID3D11ShaderResourceView* Load(wstring file);
	static void Remove(wstring file);

private:
	struct SpriteDesc
	{
		UINT RefCount = 0;
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> SRV;
	};

	static map<wstring, SpriteDesc> sprite_map;
};