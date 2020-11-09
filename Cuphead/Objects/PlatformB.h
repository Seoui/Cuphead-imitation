#pragma once
#include "Objects/Platform.h"

class PlatformB :public Platform
{
public:
	PlatformB(Vector2 _position, Vector2 _scale = Vector2(1, 1));
	~PlatformB() = default;

public:
	virtual void Update(Matrix& V, Matrix& P) override;
	virtual void Render() override;
	virtual void Play() override;

public:
	Vector2 RightUpPos();
	Vector2 LeftUpPos();

private:
	unique_ptr<Clip> platformB;
	Vector2 right_up;
	Vector2 left_up;
};