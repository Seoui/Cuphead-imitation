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
	// 총알 10개 미리 생성 번갈아가면서 쓴다
	// 총알 타입에 따라 바뀔 수 있도록 템플릿화 할 수 있지 않을까.
	// 원형 큐 사용
	for (int i = 0; i < num_bullet; ++i)
		peashots.push_back(make_unique<Peashot>(bullet_position, bullet_scale));
}

void CupheadController::Left(Vector2& position, Vector3& rotation)
{
	// dash 중엔 이동할 수 없다
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
	// 상동
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
	// 점프키를 누른 순간 
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
	// 점프키를 뗀 순간
	if (jump_speed / gravity > jump_time)
		jump_time = (2 * jump_speed) / gravity - jump_time;
	else
		jump_time = jump_time;
	b_fall = true;
}

void CupheadController::Dash(Vector2& position, float forwardVector)
{
	// 대쉬는 한번의 점프에서 한번만 할 수 있다.
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
	// 맞으면 살짝 고정 점프 하고 
	// 몇초동안 무적이고
	// 카메라 흔들림이 있다.
	// 맞는 순간 위치
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
		// 대쉬하는 도중 hit
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
	// 점프 했을 때
	else if (b_jump)
	{
		// 점프 중 대쉬 하는 경우
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
		// 점프 중 라인에 충돌하는 경우(플랫폼)
		else if ((b_line_collision == true) && (b_fall == true))
		{
			position.y -= 400.0f * Time::Delta();

			if (floor_height >= position.y)// 완전히 착지
			{
				position.y = floor_height;
				b_jump = false;
				b_ground = true;
				b_fall = false;
				b_on_platform = true;
				num_dash = 0;
			}
		}
		// 점프 
		else
		{
			jump_height = (-gravity * jump_time * jump_time / 2) + (jump_time * jump_speed);
			jump_time += jump_time_weight * Time::Delta();
			position.y = jump_start_height + jump_height;

			if (jump_height > 320)
				b_fall = true;

			if (jump_start_height > position.y)// 완전히 착지
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
	// 컵헤드가 플랫폼 위에 서있는 경우
	else if (b_line_collision == true && b_on_platform == true)
	{
		position.y = floor_height;
		b_ground = true;
	}
	// 컵헤드가 플랫폼에서 그냥 떨어지는 경우
	else if (b_line_collision == false && position.y > -240)
	{
		position.y -= 1400.0f * Time::Delta();
		b_ground = true;
		b_on_platform = false;
	}
	/*
		선과 선이 만난다.
		[1]컵헤드의 선과 플랫폼의 선이 만난다.
			1. 컵헤드가 점프를 하는 도중 플랫폼의 선과 충돌하는 경우
				1.1 플랫폼에 충돌 후 정확히 플랫폼의 높이에 착지하는 경우 -> 항상 낙하일때만 가능

				1.2 플랫폼에 충돌은 했지만 당장은 플랫폼의 높이에 착지하지 않는 경우
					착지 할 수도 있고 착지 안할 수도 있다. -> 점프 상승일 경우이다.
					-> 낙하도중에 충돌했으면 착지 안할수는 없음

			2. 컵헤드가 플랫폼 위에 서있는 경우

		[2]컵헤드의 선과 플랫폼의 선이 만나지 않은 경우.
			1. 바닥에 있는 경우
			2. 플랫폼 위에 서 있다가, 옆으로 이동하여 플랫폼에서 떨어지는 경우


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
