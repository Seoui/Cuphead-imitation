#include "stdafx.h"
#include "Cuphead.h"

Cuphead::Cuphead(Vector2 _position, Vector2 _scale)
	: Actor(_position, _scale),
	b_turn(false), state(CUPHEAD_STATE::Intro),
	line_start(0, 0), line_end(0, 0)
{
	animation = make_unique<CupheadAnimation>(_position, _scale);
	animation->Play(CUPHEAD_STATE::Intro);
	controller = make_unique<CupheadController>(_position);
}

void Cuphead::Update(Matrix & V, Matrix & P)
{
	if (state == CUPHEAD_STATE::Intro)
		if (animation->IsPlayEnd(26))
			state = CUPHEAD_STATE::Idle;
	
	// cuphead�� line
	line_end = Vector2(position.x, position.y - 15.0f);
	line_start = Vector2(line_end.x, line_end.y + 50.0f);
	// cuphead�� ��� �ൿ ó��
	ProcessBehavior(V, P);
	// cuphead �ִϸ��̼�
	animation->Position(position);
	animation->Rotation(rotation);
	animation->Update(V, P);	
	// cuphead�� collider
	collider->World(animation->World(), Vector2(0.7f, 0.7f));
	collider->Update(V, P);
}

void Cuphead::ProcessBehavior(Matrix& V, Matrix& P)
{
	// �ִϸ��̼��� ���溤��
	float forwardVector = animation->ForwardVector();

	// ��� state�� ���� idle state ����
	bool bDash = controller->IsDash();
	bool bJump = controller->IsJump();
	bool bHit = controller->IsHit();
	bool bAction = bDash | bJump | bHit;
	if (bAction == false && state != CUPHEAD_STATE::Intro)
		state = CUPHEAD_STATE::Idle;

	//HX move(left, right) => turnaround �����ؾ� ��
	if (Key->Press(VK_LEFT))
	{
		controller->Left(position, rotation);
		if (bHit == false)
			state = CUPHEAD_STATE::RunNormal;
	}
	else if (Key->Press(VK_RIGHT))
	{
		controller->Right(position, rotation);
		if(bHit == false)
			state = CUPHEAD_STATE::RunNormal;
	}
	if (Key->Press(VK_UP)) 
	{
		if (bHit == false)
			state = CUPHEAD_STATE::ShootUp;
	}
	else if (Key->Press(VK_DOWN)) 
	{
		controller->Down(position);
		if(bHit == false)
			state = CUPHEAD_STATE::Duck;
	}

	// jump
	if (Key->Down('Z')) 
	{
		if(bHit == false)
			controller->StartJump(position);
	}
	else if (Key->Up('Z'))
		controller->EndJump();
	if (bJump == true)
		state = CUPHEAD_STATE::Jump;

	//HX dash => dashGround, dashAir �����ؾ� ��
	if (Key->Down(VK_SHIFT))
		controller->Dash(position, forwardVector);
	if (bDash == true && bHit == false)
		state = CUPHEAD_STATE::DashGround;

	// lock-in
	if (Key->Press('C')) {}
	if (Key->Up('C')) {}

	// ���� ���
	if (Key->Press('X') && state == CUPHEAD_STATE::Idle)
	{
		if(bDash == false)
			controller->Shoot(position, forwardVector);
		if(bJump == false && bDash == false && bHit == false)
			state = CUPHEAD_STATE::ShootStraight;
	}
	// ���� ���
	else if (Key->Press('X') && state == CUPHEAD_STATE::Jump)
	{
		if (bDash == false)
			controller->Shoot(position, forwardVector);
	}
	// �ɾƼ� ���
	else if (Key->Press('X') && state == CUPHEAD_STATE::Duck)
	{
		if (bDash == false)
			controller->Shoot(Vector2(position.x, position.y - 30), forwardVector);
		if (bJump == false && bDash == false && bHit == false)
			state = CUPHEAD_STATE::DuckShoot;
	}
	// �޸��鼭 ���
	else if (Key->Press('X') && state == CUPHEAD_STATE::RunNormal)
	{
		if (bDash == false)
			controller->Shoot(position, forwardVector);
		if (bJump == false && bDash == false && bHit == false)
			state = CUPHEAD_STATE::RunShootingStraight;
	}
	// ���� ���
	else if (Key->Press('X') && Key->Press(VK_UP))
	{
		if(bDash == false)
			controller->ShootUp(position, forwardVector);
		if (bJump == false && bDash == false && bHit == false)
			state = CUPHEAD_STATE::ShootUp;
	}
	/*
	else if (Key->Up('X'))
		controller->EndShoot();
	*/

	// special attack
	if (Key->Down('V')) {}

	// hit
	if (bHit == true)
	{
		d_hit_cool_time += Time::Delta();
		if (d_hit_cool_time < hit_cool_time)
		{
			state = CUPHEAD_STATE::HitGround;
			d_hit_cool_time = 0;
		}
		else
			state = CUPHEAD_STATE::Idle;
	}

	if (Key->Press(VK_F5))
	{
		position = Vector2(-200, -100);
		animation->Position(Vector2(-200, -100));
	}

	animation->Play(state);
	// jump, dash ���� controller���� �ۿ��ϴ� ��
	controller->UpdateForce(position);
	// shoot, special attack ���� controller���� �ִϸ��̼� ��� 
	controller->UpdateAnimation(V, P);
}

void Cuphead::Render()
{ 
	controller->Render();
	animation->Render();
	//collider->Render();
}

Sprite * Cuphead::GetSprite()
{
	return animation->CurrentSprite();
}

Matrix & Cuphead::CollisionWorld()
{
	return collider->World();
}

CupheadController * Cuphead::GetController()
{
	return controller.get();
}

vector<unique_ptr<Peashot>>& Cuphead::Peashots()
{
	return controller->Peashots();
}

vector<unique_ptr<Weapon>>& Cuphead::CurrentWeapon()
{
	return current_weapon;
}