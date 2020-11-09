#pragma once
#include "Camera.h"

class Freedom : public Camera
{
public:
	Freedom(float speed = 500.0f);
	~Freedom() = default;
	void Update() override;

	void Position(float x, float y);
	void Position(Vector2& vec);

	void Speed(float val) { speed = val; }

private:
	void Move(Vector2 translation);

private:
	float speed;
};