#pragma once
#include "Objects/Weapon.h"

class Peashot : public Weapon
{
public:
	Peashot(Vector2 _position, Vector2 _scale = Vector2(1, 1));
	~Peashot() = default;

public:
	void Update(Matrix& V, Matrix& P) override;
	void Render() override;
	void Shoot(Vector2 _startPosition, float _forwardVector) override;
	void Stop() override;

public:
	void ShootUp(Vector2 _startPosition, float forwardVector);

private:
	const float peashot_speed = 1500.0f;
	const UINT  repeat_idx = 7;
	Vector2 dir;
};