#include "stdafx.h"
#include "CupheadController.h"
#include "Objects/Weapon.h"

CupheadController::CupheadController(Vector2& position)
	: move_speed(350.0f), jump_speed(80.0f), dash_speed(850.0f), gravity(9.8f)
	, jump_height(0.0f), jump_time(0.0f), delta_dash_dist(0.0f), dash_air_height(0.0f)
	, jump_start_height(position.y), b_ground(true), b_jump(false), b_aim(false)
	, b_dash(false), bullet_position(-500, -500)
	, bullet_scale(1, 1), num_dash(0), bullet_index(0)
	, num_bullet(10), shoot_delay(1.0f)
	, b_shoot(false), delta_time(0), b_hit(false), hit_pos(0, 0)
{
	// �Ѿ� 10�� �̸� ���� �����ư��鼭 ����
	// �Ѿ� Ÿ�Կ� ���� �ٲ� �� �ֵ��� ���ø�ȭ �� �� ���� ������.
	// ���� ť ���
	for (int i = 0; i < num_bullet; ++i)
		peashots.push_back(make_unique<Peashot>(bullet_position, bullet_scale));
}

void CupheadController::Left(Vector2& position, Vector3& rotation)
{
	// dash �߿� �̵��� �� ����
	if (!b_dash)
	{
		if (position.x < -640)
			position.x = -640;
		position.x -= move_speed * Time::Delta();
		rotation.y = Math::PI;
	}
}

void CupheadController::Right(Vector2& position, Vector3& rotation)
{
	// ��
	if(!b_dash)
	{
		position.x += move_speed * Time::Delta();
		rotation.y = 0;
	}
}

void CupheadController::Up()
{

}

void CupheadController::Down(Vector2& position)
{
	if (!b_dash)
	{
		//position.y -= 50;
	}
}

void CupheadController::StartJump(Vector2& position)
{
	// ����Ű�� ���� ���� 
	if (b_ground == true)
	{
		b_jump = true;
		b_fall = false;
		b_ground = false;
		b_on_platform = false;
		jump_time = 0.0f;
		num_dash = 0;
		jump_start_height = position.y;
	}
}

void CupheadController::EndJump()
{
	// ����Ű�� �� ����
	if (jump_speed / gravity > jump_time)
		jump_time = (2 * jump_speed) / gravity - jump_time;
	else
		jump_time = jump_time;
	b_fall = true;
}

void CupheadController::Dash(Vector2& position, float forwardVector)
{
	// �뽬�� �ѹ��� �������� �ѹ��� �� �� �ִ�.
	num_dash++;
	if(num_dash < 2)
	{
		b_dash = true;
		dash_speed = abs(dash_speed) * forwardVector;
		dash_air_height = position.y;
	}
}

void CupheadController::Shoot(Vector2& position, float forwardVector)
{
	b_shoot = true;
	shoot_delay += Time::Delta();

	if (shoot_delay > shoot_time_interval)
	{
		if (bullet_index > num_bullet -1 ) 
			bullet_index = 0;
		peashots[bullet_index++]->Shoot(Vector2(position.x, position.y + 65), forwardVector);
		shoot_delay = 0;
	}
}

void CupheadController::ShootUp(Vector2 & position, float forwardVector)
{
	b_shoot = true;
	shoot_delay += Time::Delta();

	if (shoot_delay > shoot_time_interval)
	{
		if (bullet_index > num_bullet - 1)
			bullet_index = 0;
		peashots[bullet_index++]->ShootUp(Vector2(position.x, position.y + 65), forwardVector);
		shoot_delay = 0;
	}
}

void CupheadController::EndShoot()
{
	b_shoot = false;
	shoot_delay = 0;
}

void CupheadController::Hit(Vector2& position)
{
	b_hit = true;
	hit_pos = position;
	// ������ ��¦ ���� ���� �ϰ� 
	// ���ʵ��� �����̰�
	// ī�޶� ��鸲�� �ִ�.
	// �´� ���� ��ġ
}

void CupheadController::UpdateForce(Vector2& position)
{
	if (b_dash)
	{
		if (b_hit == false)
		{
			delta_dash_dist += dash_speed * Time::Delta();
			if (abs(delta_dash_dist) < dash_distance)
				position.x += dash_speed * Time::Delta();
			else
			{
				b_dash = false;
				delta_dash_dist = 0;
				num_dash = 0;
			}
		}
		// �뽬�ϴ� ���� hit
		else
		{
			b_dash = false;
			delta_dash_dist = 0;
			num_dash = 0;
		}
	}
	else if (b_hit)
	{
		jump_height = (-gravity * delta_time * delta_time) + (delta_time * jump_speed);
		delta_time += jump_time_weight * Time::Delta();
		position.y = hit_pos.y + jump_height;

		if (position.y < hit_pos.y)
		{
			position.y = hit_pos.y;
			delta_time = 0;
			b_hit = false;
		}
	}
	// ���� ���� ��
	else if (b_jump)
	{
		// ���� �� �뽬 �ϴ� ���
		if (b_dash)
		{
			delta_dash_dist += dash_speed * Time::Delta();
			if (abs(delta_dash_dist) < dash_distance)
			{
				position.x += dash_speed * Time::Delta();
				position.y = dash_air_height;
			}
			else
			{
				b_dash = false;
				delta_dash_dist = 0;
			}
		}
		// ���� �� ���ο� �浹�ϴ� ���(�÷���)
		else if ((b_line_collision == true) && (b_fall == true))
		{
			position.y -= 400.0f * Time::Delta();

			if (floor_height >= position.y)// ������ ����
			{
				position.y = floor_height;
				b_jump = false;
				b_ground = true;
				b_fall = false;
				b_on_platform = true;
				num_dash = 0;
			}
		}
		// ���� 
		else
		{
			jump_height = (-gravity * jump_time * jump_time / 2) + (jump_time * jump_speed);
			jump_time += jump_time_weight * Time::Delta();
			position.y = jump_start_height + jump_height;

			if (jump_height > 320)
				b_fall = true;

			if (jump_start_height > position.y)// ������ ����
			{
				position.y = jump_start_height;
				b_jump = false;
				b_ground = true;
				b_fall = false;
				b_on_platform = false;
				num_dash = 0;
			}
		}
	}
	// ����尡 �÷��� ���� ���ִ� ���
	else if (b_line_collision == true && b_on_platform == true)
	{
		position.y = floor_height;
		b_ground = true;
	}
	// ����尡 �÷������� �׳� �������� ���
	else if (b_line_collision == false && position.y > -240)
	{
		position.y -= 1400.0f * Time::Delta();
		b_ground = true;
		b_on_platform = false;
	}
	/*
		���� ���� ������.
		[1]������� ���� �÷����� ���� ������.
			1. ����尡 ������ �ϴ� ���� �÷����� ���� �浹�ϴ� ���
				1.1 �÷����� �浹 �� ��Ȯ�� �÷����� ���̿� �����ϴ� ��� -> �׻� �����϶��� ����

				1.2 �÷����� �浹�� ������ ������ �÷����� ���̿� �������� �ʴ� ���
					���� �� ���� �ְ� ���� ���� ���� �ִ�. -> ���� ����� ����̴�.
					-> ���ϵ��߿� �浹������ ���� ���Ҽ��� ����

			2. ����尡 �÷��� ���� ���ִ� ���

		[2]������� ���� �÷����� ���� ������ ���� ���.
			1. �ٴڿ� �ִ� ���
			2. �÷��� ���� �� �ִٰ�, ������ �̵��Ͽ� �÷������� �������� ���


	*/
}
	
void CupheadController::UpdateAnimation(Matrix & V, Matrix & P)
{
	if(b_shoot)
	{
		for (int i = 0; i < num_bullet; ++i)
			peashots[i]->Update(V, P);
	}
}

void CupheadController::Render()
{
	if(b_shoot)
	{
		for (int i = 0; i < num_bullet; ++i)
			peashots[i]->Render();
	}
}

void CupheadController::Aim(bool state)
{
	b_aim = state;
}
