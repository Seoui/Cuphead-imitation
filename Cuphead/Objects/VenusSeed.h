#pragma once
#include "EnemyObject.h"

enum class VENUS_SEED_STATE { Fall, Grow };

class VenusSeed : public EnemyObject
{
public:
	VenusSeed(Vector2 _position, Vector2 _scale = Vector2(1, 1));
	~VenusSeed() = default;

public:
	void Update(Matrix& V, Matrix& P) override;
	void Render() override;

public:
	void Play(VENUS_SEED_STATE state);
	bool IsPlayEnd(VENUS_SEED_STATE state);
	void Spawn(Vector2 _position);
	void Die();
	void Wait();
	bool IsLive();
	bool IsDead();
	Vector2& GrowPosition();
	
private:
	unique_ptr<Animation> seed_anim;
	Vector2 grow_pos;
	bool b_live;
	bool b_dead;
};