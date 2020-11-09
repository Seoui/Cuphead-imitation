#pragma once
#include "Character/Attackable.h"
#include "Character/Bosses/CagneyAnimation.h"
#include "Generator/ChomperGenerator.h"
#include "Generator/MiniFlowerGenerator.h"
#include "Generator/VenusFlytrapGenerator.h"
#include "Generator/AcornGenerator.h"
#include "Generator/BoomerangGenerator.h"
#include "Generator/VineGenerator.h"
#include "Generator/PollenGenerator.h"

enum class CAGNEY_SKILL
{
	Idle, FiringSeeds, FaceAttack, CreatingObject,
	FiringPollen, CreatingVine, Dead, Nothing
};

class Cagney : public Attackable
{
public:
	Cagney(Vector2 _position, Vector2 _scale = Vector2(1, 1));
	~Cagney() = default;

public:
	void Update(Matrix& V, Matrix& P) override;
	void Render() override;

public:
	void Phase1();
	void Phase2();
	void Die();
	void FiringSeeds();
	void FaceAttack();
	void CreatingObject();
	void FiringPollen();
	void CreatingVine();
	bool IsDead();
	bool IsPlayEnd(CAGNEY_ANIM state);
	void CupheadPosition(Vector2 _position);

private:
	unique_ptr<CagneyAnimation> cagney_anim;
	unique_ptr<ChomperGenerator> chomper_gen;
	unique_ptr<MiniFlowerGenerator> flower_gen;
	unique_ptr<VenusFlytrapGenerator> flytrap_gen;
	unique_ptr<AcornGenerator> acorn_gen;
	unique_ptr<BoomerangGenerator> boomerang_gen;
	unique_ptr<PollenGenerator> pollen_gen;
	unique_ptr<VineGenerator> vine_gen;

	unique_ptr<class SeedMissile> seed_missile;

	CAGNEY_ANIM anim_state;
	CAGNEY_SKILL skill_state;
	const float creating_time = 1.3f;
	float d_creating_time = 0;
	const float cool_time = 13;
	float d_cool_time = -22;
	const float pollen_cool_time = 8;
	float d_pollen_cool_time = -5;
	bool c_first = false;
	bool c_second = false;
	bool c_third = false;
	bool f_pos = false;
	bool c_vine = false;
	bool p_once = false;
	random_device rd;
};