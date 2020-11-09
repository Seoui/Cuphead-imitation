#pragma once
#include "Character/Attackable.h"

enum class CHOMPER_STATE { Normal, Dead };

class Chomper : public Attackable
{
public:
	Chomper(Vector2 _position, Vector2 _scale = Vector2(1, 1));
	~Chomper() = default;

public:
	void Update(Matrix& V, Matrix& P) override;
	void Render() override;

public:
	void Play(CHOMPER_STATE state);
	bool IsPlayEnd(CHOMPER_STATE state);
	void Spawn(Vector2 _position);
	void Die();
	bool IsLive();

private:
	unique_ptr<Animation> chomper_anim;
	bool b_live;
};