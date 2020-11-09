#pragma once
#include "Objects/EnemyObject.h"

class Pollen : public EnemyObject
{
public:
	Pollen(Vector2 _position, Vector2 _scale = Vector2(1, 1));
	~Pollen() = default;

public:
	void Update(Matrix& V, Matrix& P) override;
	void Render() override;

public:
	void Play();
	bool IsPlayEnd();
	void Spawn(Vector2 _position);
	void Die();
	bool IsLive();
	void CupheadPosition(Vector2 _position);

private:
	unique_ptr<Clip> pollen_pink;
	unique_ptr<Clip> pollen_white;
	Vector2 cuphead_pos;
	bool b_live;
	bool b_rand;
	float duration = 0;
};