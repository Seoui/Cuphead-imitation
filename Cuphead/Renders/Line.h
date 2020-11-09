#pragma once

class Line
{
public:
	Line(Vector2 A, Vector2 B);
	~Line();

	void Update(Matrix& V, Matrix& P);
	void Render();

	void Left(Vector2& vec) { left = vec; }
	void Right(Vector2& vec) { right = vec; }

	Vector2 Left() { return left; }
	Vector2 Right() { return right; }
	
	void Position(float x, float y);
	void Position(Vector2& vec);
	Vector2 Position() { return position; }

	void Scale(float x, float y);
	void Scale(Vector2& vec);
	Vector2 Scale() { return scale; }

private:
	void CreateBuffer(Vector2 A, Vector2 B);

private:
	struct Vertex
	{
		Vector3 Position;
	} vertices[2];

private:
	Shader* shader;
	ID3D11Buffer* vertexBuffer;
	
	Vector2 position;
	Vector2 scale;

	Vector2 left;
	Vector2 right;

	ID3DX11EffectMatrixVariable* sWorld;
	ID3DX11EffectMatrixVariable* sView;
	ID3DX11EffectMatrixVariable* sProjection;
};