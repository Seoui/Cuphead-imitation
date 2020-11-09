#pragma once
#include "Actor.h"

class Attackable : public Actor
{
public:
	Attackable()
		: Actor(), health(100)
	{
		Matrix W;
		D3DXMatrixIdentity(&W);
		W._41 = 1000.0f;
		W._42 = 1000.0f;
		collider->World(W);
	}
	Attackable(Vector2 _position, Vector2 _scale)
		: Actor(_position, _scale), health(100)
	{
		Matrix W;
		D3DXMatrixIdentity(&W);
		W._41 = 1000.0f;
		W._42 = 1000.0f;
		collider->World(W);
	}
	virtual ~Attackable() = default;
	void TakenDamage() { health -= 5; }

protected:
	float health;
};