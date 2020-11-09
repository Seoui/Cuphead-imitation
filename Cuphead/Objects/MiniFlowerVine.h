#pragma once
#include "EnemyObject.h"

class MiniFlowerVine : public EnemyObject
{
public:
	MiniFlowerVine(Vector2 _position, Vector2 _scale = Vector2(1, 1));
	~MiniFlowerVine() = default;

public:
	void Update(Matrix& V, Matrix& P) override;
	void Render() override;

public:
	void Play();
	bool IsPlayEnd();
	void Spawn(Vector2 _position);
	void Die();
	void Wait();
	bool IsLive();
	bool IsDead();
	bool IsGrow();

private:
	unique_ptr<Clip> vine_clip;
	bool b_live;
	bool b_dead;
	bool b_grow;
};