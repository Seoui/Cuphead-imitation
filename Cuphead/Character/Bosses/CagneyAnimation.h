#pragma once

enum class CAGNEY_ANIM
{
	Intro = 0,
	Idle,
	FaceAttackHigh,
	FaceAttackLow,
	CreatingObject,
	FiringSeeds,
	FinalIntro,
	FinalIdle,
	FiringPollen,
	Dead
};

class CagneyAnimation : public Animation
{
public:
	CagneyAnimation(Vector2 _position, Vector2 _scale);
	~CagneyAnimation() = default;
	void Play(CAGNEY_ANIM state);
};