#pragma once
#include "Character/Attackable.h"

enum class FLYTRAP_STATE { Normal, Attack, Dead };

class VenusFlytrap : public Attackable
{
public:
	VenusFlytrap(Vector2 _position, Vector2 _scale = Vector2(1, 1));
	~VenusFlytrap() = default;

public:
	void Update(Matrix& V, Matrix& P) override;
	void Render() override;

public:
	void CupheadPosition(Vector2 _position);
	void Play(FLYTRAP_STATE state);
	bool IsPlayEnd(FLYTRAP_STATE state);
	void Spawn(Vector2 _position);
	void Die();
	bool IsLive();
	
private:
	unique_ptr<Animation> flytrap_anim;
	Vector2 cuphead_pos;
	bool b_live;
};