#pragma once

class Camera
{
public:
	Camera();
	virtual	~Camera() = default;
	virtual void Update();

	Matrix View() const { return view; }
	Vector2 Position() const { return position; }

protected:
	Vector2 position;

private:
	Matrix view;
};