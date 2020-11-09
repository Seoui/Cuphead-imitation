#pragma once
#include "Objects/EnemyObject.h"
#include "Objects/FinalSubVine.h"

class FinalMainVine : public EnemyObject
{
public:
	FinalMainVine(Vector2 _position, Vector2 _scale = Vector2(1, 1));
	~FinalMainVine() = default;

public:
	void Update(Matrix& V, Matrix& P) override;
	void Render() override;

public:
	void Spawn(Vector2 _position);
	void Die();
	bool IsLive();
	void AttackPlatform();

private:
	unique_ptr<Clip> vine_main;
	unique_ptr<Clip> vine_platform1;
	unique_ptr<Clip> vine_platform2;
	unique_ptr<Clip> vine_platform3;
	vector<unique_ptr<Clip>> vine_platforms;
	vector<unique_ptr<Collider>> platform_colliders;
	vector<unique_ptr<FinalSubVine>> sub_vines;

	float d_cool_time = 0;
	const float cool_time = 3;
	float vine_interval = 1;
	float d_vine_interval = 0;
	bool b_live;
	random_device rd;
	int count = 0;
	int precedence = 0;
};