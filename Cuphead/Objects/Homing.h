#pragma once
#include "Objects/Weapon.h"

class Homing : public Weapon
{
public:
	Homing(Vector2 _position, Vector2 _scale = Vector2(1, 1));
	~Homing() = default;

public:
	void Update(Matrix& V, Matrix& P) override;
	void Render() override;
	void Shoot(Vector2 _startposition, float _forwardVector) override;
	void Stop() override;
	
private:
	const float homing_speed = 800.0f;
	const UINT  repeat_idx = 0;
};