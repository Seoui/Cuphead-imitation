#pragma once
#include "Object.h"

class Weapon : public Object
{
public:
	Weapon()
		: Object()
		, hitFX_pos(-500, -500), fireFX_pos(-500, -500)
		, direction(0.0f), bShoot(false), bStop(false)
		, clip(nullptr), fireFX(nullptr), hitFX(nullptr) 
	{
		Matrix W;
		D3DXMatrixIdentity(&W);
		W._41 = -1000.0f;
		W._42 = -1000.0f;
		collider->World(W);
	}
	Weapon(Vector2 _position, Vector2 _scale)
		: Object(_position, _scale)
		, hitFX_pos(-500, -500), fireFX_pos(-500, -500)
		, direction(0.0f), bShoot(false), bStop(false)
		, clip(nullptr), fireFX(nullptr), hitFX(nullptr)
	{
		Matrix W;
		D3DXMatrixIdentity(&W);
		W._41 = -1000.0f;
		W._42 = -1000.0f;
		collider->World(W);
	}
	virtual ~Weapon() = default;

public:
	virtual void Shoot(Vector2 _position, float _forwardVector) = 0;
	virtual void Stop() = 0;

protected:
	const float left_bound = -1000.0f;
	const float right_bound = +1000.0f;
	unique_ptr<Clip> clip; // ÃÑ¾Ë Å¬¸³
	unique_ptr<Clip> fireFX;
	unique_ptr<Clip> hitFX;
	Vector2 hitFX_pos;
	Vector2 fireFX_pos;
	float direction;
	bool bShoot;
	bool bStop;
};