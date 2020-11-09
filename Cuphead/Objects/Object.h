#pragma once

class Object
{
public:
	Object()
		: position(0, 0)
		, scale(1, 1)
		, rotation(0, 0, 0)
	{
		collider = make_unique<Collider>();
		shader_file = L"Object.fx";
	}
	Object(Vector2 _position, Vector2 _scale)
		: position(_position)
		, scale(_scale)
		, rotation(0, 0, 0)
	{
		collider = make_unique<Collider>();
		shader_file = L"Object.fx";
	}
	virtual ~Object() = default;
	void Position(Vector2 vec) { position = vec; }
	Vector2 Position() { return position; }
	void Rotation(Vector3 vec) { rotation = vec; }
	Vector3 Rotation() { return rotation; }
	void Scale(Vector2 vec) { scale = vec; }
	Vector2 Scale() { return scale; }
	Matrix& CollisionWorld() { return collider->World(); }

public:
	virtual void Update(Matrix& V, Matrix& P) = 0;
	virtual void Render() = 0;

protected:
	unique_ptr<Collider> collider;
	Vector2 position;
	Vector2 scale;
	Vector3 rotation;
	wstring shader_file;
};