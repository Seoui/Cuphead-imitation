#pragma once
#include "Character/Actor.h"
#include "Character/Cuphead/CupheadController.h"
#include "Character/Cuphead/CupheadAnimation.h"

class Cuphead : public Actor
{
public:
	Cuphead(Vector2 _position, Vector2 _scale = Vector2(1, 1));
	~Cuphead() = default;

public:
	void Update(Matrix &V, Matrix& P) override;
	void Render() override;

public:
	void ProcessBehavior(Matrix& V, Matrix& P);
	vector<unique_ptr<Peashot>>& Peashots();
	vector<unique_ptr<Weapon>>& CurrentWeapon();
	CupheadController* GetController();
	Matrix& CollisionWorld();
	Sprite* GetSprite();
	Vector2 LineStart() { return line_start; }
	Vector2 LineEnd() { return line_end; }
	void SetFloorHeight(float height) { controller->SetFloorHeight(height); }
	void LineCollision(bool b) { controller->LineCollision(b); }

private:
	unique_ptr<CupheadController> controller;
	unique_ptr<CupheadAnimation> animation;
	vector<unique_ptr<Weapon>> current_weapon;
	CUPHEAD_STATE state;
	bool b_turn;
	Vector2 line_start;
	Vector2 line_end;
	const float hit_cool_time = 2;
	float d_hit_cool_time = 0;
};