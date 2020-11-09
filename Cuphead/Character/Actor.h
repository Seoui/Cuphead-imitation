#pragma once

class Actor
{
public:
	Actor()
		: scale(1, 1)
		, rotation(0, 0, 0)
		, position(0, 0)
	{
		collider = make_unique<Collider>();
		shader_file = L"Actor.fx";
	}
	Actor(Vector2 _position, Vector2 _scale)
		: scale(_scale)
		, rotation(0, 0, 0)
		, position(_position)
	{
		collider = make_unique<Collider>();
		shader_file = L"Actor.fx";
	}
	virtual ~Actor() = default;
	void Position(Vector2 vec) { position = vec; }
	Vector2 Position() { return position; }
	Matrix& CollisionWorld() { return collider->World(); }

public:
	virtual void Update(Matrix& V, Matrix& P) = 0;
	virtual void Render() = 0;

protected:
	unique_ptr<Collider> collider;
	wstring shader_file;
	Vector2 scale;
	Vector3 rotation;
	Vector2 position;
};