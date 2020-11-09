#pragma once

class FloralFury
{
public:
	FloralFury(Vector2 _position);
	~FloralFury() = default;
	void Update(Matrix& V, Matrix& P);
	void Render();

private:
	unique_ptr<Sprite> main;
	unique_ptr<Sprite> hill;
	unique_ptr<Sprite> sky;
	unique_ptr<Sprite> wind1;
	unique_ptr<Sprite> wind2;
	unique_ptr<Sprite> sea;
};