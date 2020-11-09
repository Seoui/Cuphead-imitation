#pragma once
#include "EnemyObject.h"

enum class MINIFLOWER_SEED_STATE { Fall, Grow };

class MiniFlowerSeed : public EnemyObject
{
public:
	MiniFlowerSeed(Vector2 _position, Vector2 _scale = Vector2(1, 1));
	~MiniFlowerSeed() = default;

public:
	void Update(Matrix& V, Matrix& P) override;
	void Render() override;

public:
	void Play(MINIFLOWER_SEED_STATE state);
	bool IsPlayEnd(MINIFLOWER_SEED_STATE state);
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