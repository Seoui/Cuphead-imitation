#include "stdafx.h"
#include "CupheadAnimation.h"
#include "Objects/PlayerAnimation/AimAnim.h"
#include "Objects/PlayerAnimation/DashAnim.h"
#include "Objects/PlayerAnimation/DeathAnim.h"
#include "Objects/PlayerAnimation/DuckAnim.h"
#include "Objects/PlayerAnimation/IdleAnim.h"
#include "Objects/PlayerAnimation/JumpAnim.h"
#include "Objects/PlayerAnimation/RunAnim.h"
#include "Objects/PlayerAnimation/ShootAnim.h"

CupheadAnimation::CupheadAnimation()
	: position(0.0f, 0.0f)
	, scale(1.0f, 1.0f)
	, rotation(0.0f, 0.0f, 0.0f)
{
	wstring shaderFile = L"Effect.fx";

	aimAnim = make_unique<AimAnim>(shaderFile);
	dashAnim = make_unique<DashAnim>(shaderFile);
	deathAnim = make_unique<DeathAnim>(shaderFile);
	duckAnim = make_unique<DuckAnim>(shaderFile);
	idleAnim = make_unique<IdleAnim>(shaderFile);
	jumpAnim = make_unique<JumpAnim>(shaderFile);
	runAnim = make_unique<RunAnim>(shaderFile);
	shootAnim = make_unique<ShootAnim>(shaderFile);

	currentAnimation = idleAnim.get();
	currentAnimation->Position(position);
	currentAnimation->Scale(scale);
	currentAnimation->Rotation(rotation);
}

CupheadAnimation::~CupheadAnimation()
{
}

//HX 흠...스프라이트 클래스는 UpdateWorld를 구분한다
// animation class들과 그 상위 구조 클래스들도 가능한지 확인 해 볼것
void CupheadAnimation::Update(Matrix & V, Matrix & P)
{
	currentAnimation->Position(position);
	currentAnimation->Scale(scale);
	currentAnimation->Rotation(rotation);
	currentAnimation->Update(V, P);
}

void CupheadAnimation::Render()
{
	currentAnimation->Render();
}

void CupheadAnimation::Position(float x, float y)
{
	Position(Vector2(x, y));
}

void CupheadAnimation::Position(Vector2 & vec)
{
	position = vec;
}

Vector2 CupheadAnimation::Position()
{
	return position;
}

void CupheadAnimation::Scale(float x, float y)
{
	Scale(Vector2(x, y));
}

void CupheadAnimation::Scale(Vector2 & vec)
{
	scale = vec;
}

Vector2 CupheadAnimation::Scale()
{
	return scale;
}

void CupheadAnimation::Rotation(float x, float y, float z)
{
	Rotation(Vector3(x, y, z));
}

void CupheadAnimation::Rotation(Vector3 & vec)
{
	rotation = vec;
}

Vector3 CupheadAnimation::Rotation()
{
	return rotation;
}

void CupheadAnimation::RotationDegree(float x, float y, float z)
{
	RotationDegree(Vector3(x, y, z));
}

void CupheadAnimation::RotationDegree(Vector3 & vec)
{
	Vector3 temp;
	temp.x = Math::ToRadian(vec.x);
	temp.y = Math::ToRadian(vec.y);
	temp.z = Math::ToRadian(vec.z);
	
	Rotation(temp);
}

Vector3 CupheadAnimation::RotationDegree()
{
	Vector3 temp = Rotation();
	temp.x = Math::ToDegree(rotation.x);
	temp.y = Math::ToDegree(rotation.y);
	temp.z = Math::ToDegree(rotation.z);

	return temp;
}

Animation * CupheadAnimation::CurrentAnim()
{
	return currentAnimation;
}

float CupheadAnimation::ForwardVector()
{
	return currentAnimation->ForwardVector();
}

void CupheadAnimation::PlayIdle(IDLE state)
{
	currentAnimation = idleAnim.get();
	currentAnimation->Play(static_cast<UINT>(state));
}

void CupheadAnimation::PlayRun(RUN state)
{
	currentAnimation = runAnim.get();
	currentAnimation->Play(static_cast<UINT>(state));
}

void CupheadAnimation::PlayShoot(SHOOT state)
{
	currentAnimation = shootAnim.get();
	currentAnimation->Play(static_cast<UINT>(state));
}

void CupheadAnimation::PlayJump(JUMP state)
{
	currentAnimation = jumpAnim.get();
	currentAnimation->Play(static_cast<UINT>(state));
}

void CupheadAnimation::PlayDuck(DUCK state)
{
	currentAnimation = duckAnim.get();
	currentAnimation->Play(static_cast<UINT>(state));
}

void CupheadAnimation::PlayAim(AIM state)
{
	currentAnimation = aimAnim.get();
	currentAnimation->Play(static_cast<UINT>(state));
}

void CupheadAnimation::PlayDash(DASH state)
{
	currentAnimation = dashAnim.get();
	currentAnimation->Play(static_cast<UINT>(state));
}

void CupheadAnimation::PlayDeath(DEATH state)
{
	currentAnimation = deathAnim.get();
	currentAnimation->Play(static_cast<UINT>(state));
}
