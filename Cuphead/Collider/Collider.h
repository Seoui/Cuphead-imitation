#pragma once
 
class Collider
{
public:
	Collider();
	~Collider();

	void Update(Matrix& V, Matrix& P);
	void Render();
	void World(Matrix& world);
	void World(Matrix& world, Vector2 scale);
	Matrix& World() { return world; }
	void Position(Vector2 vec);

	//static bool Aabb(Matrix& world, Vector2& position);
	static bool Aabb(Matrix& world1, Matrix& world2);
	void DrawColliderColor(bool val) { bDrawColliderColor = val; }

private:
	struct Vertex
	{
		Vector3 Position;
	};

private:
	Shader*	shader;
	ID3D11Buffer* vertexBuffer;

	Matrix world;
	ID3DX11EffectMatrixVariable* sWorld;
	ID3DX11EffectMatrixVariable* sProjection;
	ID3DX11EffectMatrixVariable* sView;
	ID3DX11EffectVectorVariable* sColor;

private:
	Color initLineColor;
	Color collidedColor;
	bool bDrawColliderColor;
};