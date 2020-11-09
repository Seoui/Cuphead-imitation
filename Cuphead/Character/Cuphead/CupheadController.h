#pragma once
#include "Objects/Peashot.h"

class CupheadController
{
public:
	CupheadController(Vector2& position);
	~CupheadController() = default;
	void UpdateForce(Vector2& position);
	void UpdateAnimation(Matrix& V, Matrix& P);
	void Render();

	// Do behavior event
	void Left(Vector2& position, Vector3& rotation);
	void Right(Vector2& position, Vector3& rotation);
	void Up();
	void Down(Vector2& position);
	void StartJump(Vector2& position);
	void EndJump();
	void Dash(Vector2& position, float forwardVector);
	void Aim(bool state);
	void Shoot(Vector2& position, float forwardVector);
	void ShootUp(Vector2& position, float forwardVector);
	void EndShoot();
	void Hit(Vector2& position);

	bool IsAim() { return b_aim; }
	bool IsGround() { return b_ground; }
	bool IsJump() { return b_jump; }
	bool IsDash() { return b_dash; }
	bool IsHit() { return b_hit; }

	vector<unique_ptr<Peashot>>& Peashots() { return peashots; }
	void SetFloorHeight(float _floor_height) { floor_height = _floor_height; }
	void LineCollision(bool line_collision) { b_line_collision = line_collision; }

private:
	const float hit_cool_time = 1.5f;
	float d_hit_cool_time = 0;
	bool b_line = false;
	Vector2 hit_pos;
	bool b_fall = false;
	float floor_height = 0;
	bool b_line_collision = false;
	bool b_on_platform = false;
	const float ground_height = -240.0f;
	const float dash_distance = 280.0f;
	const float shoot_time_interval = 0.15f;
	const float jump_time_weight = 25.0f;
	float gravity;
	float move_speed;
	float jump_speed;
	float dash_speed;
	float jump_start_height;
	float jump_height;
	float jump_time;
	float delta_dash_dist;
	float dash_air_height;
	float shoot_delay;
	float delta_time;
	int num_dash;
	int bullet_index;
	int num_bullet;
	bool b_ground;
	bool b_jump;
	bool b_aim;
	bool b_dash;
	bool b_shoot;
	bool b_hit;
	Vector2 bullet_position;
	Vector2 bullet_scale;
	vector<unique_ptr<Peashot>> peashots;
};