#include "stdafx.h"
#include "Cagney.h"
#include "Objects/SeedMissile.h"

Cagney::Cagney(Vector2 _position, Vector2 _scale)
	: Attackable(_position, _scale),
	anim_state(CAGNEY_ANIM::Intro),
	skill_state(CAGNEY_SKILL::Nothing)
{
	health = 3000;
	cagney_anim = make_unique<CagneyAnimation>(_position, _scale);
	seed_missile = make_unique<SeedMissile>(Vector2(295, 285));
	// firing seeds/
	chomper_gen = make_unique<ChomperGenerator>();
	flower_gen = make_unique<MiniFlowerGenerator>();
	flytrap_gen = make_unique<VenusFlytrapGenerator>();
	// creating object
	acorn_gen = make_unique<AcornGenerator>();
	boomerang_gen = make_unique<BoomerangGenerator>();
	// firing pollen
	pollen_gen = make_unique<PollenGenerator>();
	// creating vine
	vine_gen = make_unique<VineGenerator>();

	StaticCollisionList::InsertAttackable(this);
}

void Cagney::Update(Matrix & V, Matrix & P)
{
	if (skill_state == CAGNEY_SKILL::Idle)
		anim_state = CAGNEY_ANIM::Idle;
	
	// phase
	if (health >= 1000)
		Phase1();
	else if (health < 1000 && health >= 0)
		Phase2();
	else if (health < 0)
		Die();
		
	// cagney's objects
	chomper_gen->Update(V, P);
	flower_gen->Update(V, P);
	flytrap_gen->Update(V, P);
	acorn_gen->Update(V, P);
	boomerang_gen->Update(V, P);
	pollen_gen->Update(V, P);
	vine_gen->Update(V, P);
	
	// cagney
	if(skill_state == CAGNEY_SKILL::FiringSeeds)
		seed_missile->Update(V, P);
	cagney_anim->Play(anim_state);
	cagney_anim->Position(position);
	cagney_anim->Update(V, P);
	Matrix W = cagney_anim->World();
	cagney_anim->World()._42 = W._42 + 120;
	collider->World(cagney_anim->World(), Vector2(0.5f, 0.4f));
	collider->Update(V, P);
}

void Cagney::Render()
{
	ImGui::LabelText("health cagney", "%0.3f", health);
	// cagney's objects
	chomper_gen->Render();
	flower_gen->Render();
	flytrap_gen->Render();
	acorn_gen->Render();
	boomerang_gen->Render();
	pollen_gen->Render();
	vine_gen->Render();
	
	// cagney
	if (skill_state == CAGNEY_SKILL::FiringSeeds)
		seed_missile->Render();
	//collider->Render();
	cagney_anim->Render();
}

void Cagney::Phase1()
{
	if (anim_state == CAGNEY_ANIM::Intro)
		if (IsPlayEnd(CAGNEY_ANIM::Intro))
			anim_state = CAGNEY_ANIM::Idle;

	// skill 선택
	d_cool_time += Time::Delta();
	if (d_cool_time > cool_time)
	{
		mt19937 g(rd());
		uniform_int_distribution<int> dis(0, 2);
		int rand = dis(g);
		switch (rand)
		{
			case 0:
			{
				FiringSeeds();
				break;
			}
			case 1:
			{
				CreatingObject();
				break;
			}
			case 2:
			{
				FaceAttack();
				break;
			}
		}
	}

	// cast skill 
	if (skill_state == CAGNEY_SKILL::FiringSeeds) 
	{
		if (IsPlayEnd(CAGNEY_ANIM::FiringSeeds))
		{
			skill_state = CAGNEY_SKILL::Idle;
			d_cool_time = 10;
		}
	}
	else if (skill_state == CAGNEY_SKILL::CreatingObject)
	{
		if (cagney_anim->CurrentClip()->CurrentFrame() == 21 && c_first == false)
		{
			c_first = true;
			int rand = Math::Random(0, 1);
			if (rand)
				acorn_gen->Spawn(1);
			else
				boomerang_gen->Spawn(1);
		}
		else if (cagney_anim->CurrentClip()->CurrentFrame() == 65 && c_second == false) 
		{
			c_second = true;
			int rand = Math::Random(0, 1);
			if (rand)
				acorn_gen->Spawn(1);
			else
				boomerang_gen->Spawn(1);
		}
		else if (cagney_anim->CurrentClip()->CurrentFrame() == 109 && c_third == false) 
		{
			c_third = true;
			int rand = Math::Random(0, 1);
			if (rand)
				acorn_gen->Spawn(1);
			else
				boomerang_gen->Spawn(1);
		}
		if (IsPlayEnd(CAGNEY_ANIM::CreatingObject))
		{
			skill_state = CAGNEY_SKILL::Idle;
			d_cool_time = 10;
			c_first = false;
			c_second = false;
			c_third = false;
		}
	}
	else if (skill_state == CAGNEY_SKILL::FaceAttack)
	{
		Vector2 size = cagney_anim->TextureSize();

		if(cagney_anim->CurrentClipNum() == (int)CAGNEY_ANIM::FaceAttackHigh &&
			f_pos == false && cagney_anim->CurrentClip()->CurrentFrame() > 19)
		{
			f_pos = true;
			position.x = position.x - size.x * 0.5f;
		}
		else if (cagney_anim->CurrentClipNum() == (int)CAGNEY_ANIM::FaceAttackLow &&
			f_pos == false && cagney_anim->CurrentClip()->CurrentFrame() > 19)
		{
			f_pos = true;
			position.x = position.x - size.x * 0.5f;
		}
		
		if (cagney_anim->CurrentClip()->CurrentFrame() > 36)
		{
			f_pos = true;
			position.x = 370;
		}
		
		if (IsPlayEnd(CAGNEY_ANIM::FaceAttackHigh) ||
			IsPlayEnd(CAGNEY_ANIM::FaceAttackLow))
		{
			skill_state = CAGNEY_SKILL::Idle;
			d_cool_time = 11;
			position.x = 370;
			f_pos = false;
		}
	}
}

void Cagney::Phase2()
{
	if (p_once == false)
	{
		anim_state = CAGNEY_ANIM::FinalIntro;
		skill_state = CAGNEY_SKILL::CreatingVine;
		cagney_anim->Play(CAGNEY_ANIM::FinalIntro);
		p_once = true;
	}

	if (anim_state == CAGNEY_ANIM::FinalIntro)
	{
		if (IsPlayEnd(CAGNEY_ANIM::FinalIntro))
			anim_state = CAGNEY_ANIM::FinalIdle;

		if (cagney_anim->CurrentClip()->CurrentFrame() == 31 && c_vine == false)
		{
			c_vine = true;
			CreatingVine();
		}
	}
		
	d_pollen_cool_time += Time::Delta();
	if (d_pollen_cool_time > pollen_cool_time)
	{
		FiringPollen();
	}

	if (anim_state == CAGNEY_ANIM::FiringPollen)
	{
		if(IsPlayEnd(CAGNEY_ANIM::FiringPollen))
			anim_state = CAGNEY_ANIM::FinalIdle;
	}
}

void Cagney::Die()
{
	anim_state = CAGNEY_ANIM::Dead;
	cagney_anim->Play(anim_state);
	skill_state = CAGNEY_SKILL::Dead;
}

void Cagney::FiringSeeds()
{
	d_cool_time = 0;
	anim_state = CAGNEY_ANIM::FiringSeeds;
	cagney_anim->Play(anim_state);
	skill_state = CAGNEY_SKILL::FiringSeeds;
	seed_missile->Play();
	int rand = Math::Random(1, 3);
	/*
		씨앗은 한번에 5개 발사한다. 1개는 항상 flower이고 나머지 4개는
		chomper와 flytrap이다. chomper와 flytrap은 적어도 1개는 발사한다.
	*/
	chomper_gen->Spawn(rand);
	flytrap_gen->Spawn(4-rand);
	flower_gen->Spawn(1);
}

void Cagney::FaceAttack()
{
	d_cool_time = 0;
	mt19937 g(rd());
	uniform_int_distribution<int> dis(1, 2);
	int rand = dis(g);
	if (rand == 1)
	{
		anim_state = CAGNEY_ANIM::FaceAttackHigh;
		cagney_anim->Play(anim_state);
	}
	else if (rand == 2)
	{
		anim_state = CAGNEY_ANIM::FaceAttackLow;
		cagney_anim->Play(anim_state);
	}
	skill_state = CAGNEY_SKILL::FaceAttack;
}

void Cagney::CreatingObject()
{
	d_cool_time = 0;
	anim_state = CAGNEY_ANIM::CreatingObject;
	cagney_anim->Play(anim_state);
	skill_state = CAGNEY_SKILL::CreatingObject;
}

void Cagney::FiringPollen()
{
	d_pollen_cool_time = 0;
	anim_state = CAGNEY_ANIM::FiringPollen;
	cagney_anim->Play(anim_state);
	skill_state = CAGNEY_SKILL::FiringPollen;
	pollen_gen->Spawn(1);
}

void Cagney::CreatingVine()
{
	d_cool_time = 0;
	vine_gen->Spawn(1);
}

bool Cagney::IsDead()
{
	return health < 0;
}

bool Cagney::IsPlayEnd(CAGNEY_ANIM anim_state)
{
	return cagney_anim->IsPlayEnd((UINT)anim_state);
}

void Cagney::CupheadPosition(Vector2 _position)
{
	if (acorn_gen != nullptr)
		acorn_gen->CupheadPosition(_position);
	if (flytrap_gen != nullptr)
		flytrap_gen->CupheadPosition(_position);
}