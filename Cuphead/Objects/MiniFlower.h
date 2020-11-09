#pragma once
#include "Character/Attackable.h"

enum class MINIFLOWER_STATE { Normal, Fire, Dead };

class MiniFlower : public Attackable
{
public:
	MiniFlower(Vector2 _position, Vector2 _scale = Vector2(1, 1));
	~MiniFlower() = default;

public:
	void Update(Matrix& V, Matrix& P) override;
	void Render() override;

public:
	void Play(MINIFLOWER_STATE state);
	bool IsPlayEnd(MINIFLOWER_STATE state);
	void Spawn(Vector2 _position);
	void Die();
	bool IsLive();

private:
	unique_ptr<Animation> flower_anim;
	bool b_live;
	float d_time;
};
