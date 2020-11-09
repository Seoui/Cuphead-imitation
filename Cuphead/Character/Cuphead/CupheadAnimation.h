#pragma once
#include "Renders/Animation.h"

enum class CUPHEAD_STATE {
	Idle = 0,
	RunNormal, RunNormalTurnaround, RunShootingStraight, 
	RunShootingStraightTurnaround, RunShootingDiagonalUp, 
	RunShootingDiagonalUpTurnaround,
	Jump,
	Duck, DuckTurn, DuckShoot,
	DashGround, DashAir,
	ShootUp,
	ShootDown, ShootStraight, ShootDiagonalUp, ShootDiagonalDown,
	AimUp,
	AimDown, AimStraight, AimDiagonalUp, AimDiagonalDown,
	Death,
	HitAir, HitGround,
	Intro,
};

class CupheadAnimation : public Animation
{
public:
	CupheadAnimation(Vector2 _position, Vector2 _scale);
	~CupheadAnimation() = default;
	void Play(CUPHEAD_STATE state);

private:
	unique_ptr<Clip> jump_dust_fx;
};