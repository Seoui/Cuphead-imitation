#pragma once
#include "Objects/EnemyObject.h"

class Boomerang : public EnemyObject
{
public:
	Boomerang(Vector2 _position, Vector2 _scale = Vector2(1, 1));
	~Boomerang() = default;

public:
	void Update(Matrix& V, Matrix& P) override;
	void Render() override;

public:
	void Play();
	bool IsPlayEnd();
	void Spawn(Vector2 _position);
	void Die();
	bool IsLive();

private:
	unique_ptr<Clip> boomerang_clip;
	unique_ptr<Clip> shadow_fx;
	unique_ptr<Clip> creating_fx;
	bool b_live;
	bool b_rotate_up;
};
