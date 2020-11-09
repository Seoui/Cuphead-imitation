#pragma once
#include "EnemyObject.h"

enum class CHOMPER_SEED_STATE { Fall, Grow };

class ChomperSeed : public EnemyObject
{
public:
	ChomperSeed(Vector2 _position, Vector2 _scale = Vector2(1, 1));
	~ChomperSeed() = default;

public:
	void Update(Matrix& V, Matrix& P) override;
	void Render() override;

public:
	void Play(CHOMPER_SEED_STATE state);
	bool IsPlayEnd(CHOMPER_SEED_STATE state);
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