#pragma once
#include "Objects/EnemyObject.h"

enum class ACORN_STATE { Rotate, Rush };

class Acorn : public EnemyObject
{
public:
	Acorn(Vector2 _position, Vector2 _scale = Vector2(1, 1));
	~Acorn() = default;

public:
	void Update(Matrix& V, Matrix& P) override;
	void Render() override;

public:
	void Play(ACORN_STATE state);
	bool IsPlayEnd(ACORN_STATE state);
	void Spawn(Vector2 _position, float _rotate_time);
	void Die();
	bool IsLive();
	void CupheadPosition(Vector2 _position);

private:
	unique_ptr<Animation> acorn_anim;
	Vector2 spawn_pos;
	Vector2 cuphead_pos;
	bool b_live;
	bool b_rush;
	float d_time;
	float rotate_time;
	float slope;
};