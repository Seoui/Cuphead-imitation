#include "stdafx.h"
#include "CagneyCarnation.h"
#include "Background/StartClip.h"
#include "Background/EndClip.h"
#include "Character/Cuphead/Cuphead.h"
#include "Renders/Line.h"
#include "Collider/LineCollider.h"
#include "Character/Bosses/Cagney.h"
#include "Collider/Collider.h"
#include "Background/FloralFury.h"
#include "Objects/PlatformA.h"
#include "Objects/PlatformB.h"
#include "Objects/PlatformC.h"

CagneyCarnation::CagneyCarnation(shared_ptr<SceneValues> values)
	: Scene(values), mouse_pos(0, 0)
{	
	// start clip
	start_clip = make_unique<StartClip>();
	// end clip
	end_clip = make_unique<EndClip>();
	// background
	background = make_unique<FloralFury>(Vector2(0, +30));
	// floor line
	floor_line = make_unique<Line>(Vector2(0, 0), Vector2(0, 0));
	// platform
	platformA = make_unique<PlatformA>(Vector2(-500, -100));
	platformB = make_unique<PlatformB>(Vector2(-260, -100));
	platformC = make_unique<PlatformC>(Vector2(-20, -100));
	// platform lines
	platform_lines.push_back(make_unique<Line>(Vector2(-500, -100), Vector2(-500, -100)));
	platform_lines.push_back(make_unique<Line>(Vector2(-260, -100), Vector2(-260, -100)));
	platform_lines.push_back(make_unique<Line>(Vector2(-20, -100), Vector2(-20, -100)));
	// cuphead
	cuphead = make_unique<Cuphead>(Vector2(-300, -240));
	// cuphead_line
	cuphead_line = make_unique<Line>(Vector2(-200, -240), Vector2(-200, -240));
	// cagney
	cagney = make_unique<Cagney>(Vector2(370, -300));
	// static collision list
	StaticCollisionList::Create();
	// etc.
}

CagneyCarnation::~CagneyCarnation()
{
	StaticCollisionList::Delete();
}

void CagneyCarnation::Update()
{
	// camera
	Matrix V = values->MainCamera->View();
	Matrix P = values->Projection;
	/* mouse
	Vector2 pos = Mouse->Position();
	pos.x = pos.x - (float)Width * 0.5f;
	pos.y = (pos.y - (float)Height * 0.5f) * -1.0f;
	Vector2 camera = values->MainCamera->Position();
	mouse_pos = pos + camera;*/
	// start clip
	start_clip->Update(V, P);
	// end clip
	end_clip->Update(V, P);
	// background
	background->Update(V, P);
	// cagney
	cagney->Update(V, P);
	cagney->CupheadPosition(cuphead->Position());
	// platform
	platformA->Update(V, P);
	platformB->Update(V, P);
	platformC->Update(V, P);
	// cuphead
	cuphead->Update(V, P);
	// platform lines
	Vector2 A_r = platformA->RightUpPos();
	Vector2 A_l = platformA->LeftUpPos();
	Vector2 B_r = platformB->RightUpPos();
	Vector2 B_l = platformB->LeftUpPos();
	Vector2 C_r = platformC->RightUpPos();
	Vector2 C_l = platformC->LeftUpPos();
	platform_lines[0]->Left(A_l);
	platform_lines[0]->Right(A_r);
	platform_lines[1]->Left(B_r);
	platform_lines[1]->Right(B_l);
	platform_lines[2]->Left(C_r);
	platform_lines[2]->Right(C_l);
	// cuphead line
	Vector2 a = cuphead->LineStart();
	Vector2 b = cuphead->LineEnd();
	cuphead_line->Left(a);
	cuphead_line->Right(b);
	// check cuphead and platform collision
	b_line_collision1 = LineCollider::LineIntersect(a, b, A_r, A_l);
	b_line_collision2 = LineCollider::LineIntersect(a, b, B_r, B_l);
	b_line_collision3 = LineCollider::LineIntersect(a, b, C_r, C_l);
	bool result = b_line_collision1 | b_line_collision2 | b_line_collision3;
	cuphead->LineCollision(result);
	if (b_line_collision1)
		cuphead->SetFloorHeight(A_l.y);
	else if (b_line_collision2)
		cuphead->SetFloorHeight(B_l.y);
	else if (b_line_collision3)
		cuphead->SetFloorHeight(C_l.y);
	for (auto& line : platform_lines)
		line->Update(V, P);
	cuphead_line->Update(V, P);
	// check cuphead and attackable collision
	num_attackable = StaticCollisionList::AttackablesSize();
	d_hit_cool_time += Time::Delta();
	for (int idx = 0; idx < num_attackable; ++idx)
	{
		b_cuphead_attackable |=
			Collider::Aabb(cuphead->CollisionWorld(), StaticCollisionList::AttackableCollisionWorld(idx));
	}
	if (b_cuphead_attackable)
	{
		if(d_hit_cool_time > hit_cool_time)
		{
			cuphead->GetController()->Hit(cuphead->Position());
			d_hit_cool_time = 0;
		}
		b_cuphead_attackable = false;
	}
	// check weapon and attackable collision
	for (auto& peashot : cuphead->Peashots())
	{
		for (int idx = 0; idx < num_attackable; ++idx)
		{
			b_peashots_attackable |=
				Collider::Aabb(peashot->CollisionWorld(), StaticCollisionList::AttackableCollisionWorld(idx));
			if (b_peashots_attackable)
			{
				peashot->Stop();
				StaticCollisionList::TakeDamage(idx);
				b_peashots_attackable = false;
			}
		}
	}
	// check cuphead and enemy object collision
	num_enemy_object = StaticCollisionList::EnemyObjectsSize();
	for (int idx = 0; idx < num_enemy_object; ++idx)
	{
		b_cuphead_enemyobject |=
			Collider::Aabb(cuphead->CollisionWorld(), StaticCollisionList::EnemyObjectCollisionWorld(idx));
	}
	if (b_cuphead_enemyobject)
	{
		if (d_hit_cool_time > hit_cool_time)
		{
			cuphead->GetController()->Hit(cuphead->Position());
			d_hit_cool_time = 0;
		}
		b_cuphead_enemyobject = false;
	}
	// game clear
	b_cagney_dead = cagney->IsDead();
	if (b_cagney_dead && b_play_once == false)
	{
		end_clip->Play();
		b_play_once = true;
	}
}

void CagneyCarnation::Render()
{
	// [ImGui]
	ImGui::LabelText("Attackable count", "%d", num_attackable);
	ImGui::LabelText("EnemyObject count", "%d", num_enemy_object);
	// background
	background->Render();
	// platform
	platformA->Render();
	platformB->Render();
	platformC->Render();
	// platform lines
	/*
	for (auto& line : platform_lines)
		line->Render();*/
	// cuphead
	cuphead->Render();
	// cuphead cuphead_line
	//cuphead_line->Render();
	// cagney
	cagney->Render();
	// start_clip
	start_clip->Render();
	// end clip
	if(b_cagney_dead)
		end_clip->Render();
}
