#include "stdafx.h"
#include "FinalMainVine.h"

FinalMainVine::FinalMainVine(Vector2 _position, Vector2 _scale)
	: EnemyObject(_position, _scale)
{
	wstring vines = L"Bosses/Cagney Carnation/Final Form/Vines/Final_Vine.png";
	vine_main = make_unique<Clip>(PlayMode::Loop);
	vine_main->AddFrame(new Sprite(vines, shader_file, 0, 0, 110, 98), 0.07f);
	vine_main->AddFrame(new Sprite(vines, shader_file, 0, 98, 134, 253), 0.07f);
	vine_main->AddFrame(new Sprite(vines, shader_file, 0, 253, 198, 444), 0.07f);
	vine_main->AddFrame(new Sprite(vines, shader_file, 0, 444, 246, 632), 0.07f);
	vine_main->AddFrame(new Sprite(vines, shader_file, 0, 632, 292, 828), 0.07f);
	vine_main->AddFrame(new Sprite(vines, shader_file, 0, 828, 362, 1033), 0.07f);
	vine_main->AddFrame(new Sprite(vines, shader_file, 0, 1033, 429, 1230), 0.07f);
	vine_main->AddFrame(new Sprite(vines, shader_file, 0, 1230, 509, 1435), 0.07f);
	vine_main->AddFrame(new Sprite(vines, shader_file, 0, 1435, 573, 1656), 0.07f);
	vine_main->AddFrame(new Sprite(vines, shader_file, 0, 1656, 635, 1872), 0.07f);
	vine_main->AddFrame(new Sprite(vines, shader_file, 0, 1872, 687, 2071), 0.07f);
	vine_main->AddFrame(new Sprite(vines, shader_file, 0, 2071, 759, 2256), 0.07f);
	vine_main->AddFrame(new Sprite(vines, shader_file, 0, 2256, 812, 2428), 0.07f);
	vine_main->AddFrame(new Sprite(vines, shader_file, 0, 2428, 837, 2578), 0.07f);
	vine_main->AddFrame(new Sprite(vines, shader_file, 0, 2578, 866, 2708), 0.07f);
	vine_main->AddFrame(new Sprite(vines, shader_file, 0, 2708, 891, 2827), 0.07f);
	vine_main->AddFrame(new Sprite(vines, shader_file, 0, 2827, 904, 2945), 0.07f);
	vine_main->AddFrame(new Sprite(vines, shader_file, 0, 2945, 926, 3060), 0.07f);
	vine_main->AddFrame(new Sprite(vines, shader_file, 0, 3060, 936, 3175), 0.07f);
	vine_main->AddFrame(new Sprite(vines, shader_file, 0, 3175, 940, 3291), 0.07f);
	vine_main->AddFrame(new Sprite(vines, shader_file, 0, 3291, 944, 3404), 0.07f);
	vine_main->AddFrame(new Sprite(vines, shader_file, 0, 3404, 946, 3530), 0.07f);
	vine_main->AddFrame(new Sprite(vines, shader_file, 0, 3530, 946, 3650), 0.07f);

	sub_vines.push_back(make_unique<FinalSubVine>());
	sub_vines.push_back(make_unique<FinalSubVine>());
	sub_vines.push_back(make_unique<FinalSubVine>());
	sub_vines[0]->Position(Vector2(-500, -265));
	sub_vines[1]->Position(Vector2(-260, -265));
	sub_vines[2]->Position(Vector2(-20, -265));
}

void FinalMainVine::Update(Matrix & V, Matrix & P)
{		
	if (b_live == true) 
	{
		d_cool_time += Time::Delta();
		if (d_cool_time > cool_time) {

			if (count < 2)
			{
				d_vine_interval += Time::Delta();
				if (vine_interval < d_vine_interval)
				{
					AttackPlatform();
					d_vine_interval = 0;
					count++;
				}
			}
			else 
			{
				d_cool_time = 0;
				count = 0;
			}
		}

		for (int i = 0; i < 3; ++i)
		{
			if (sub_vines[i]->IsPlayEnd())
			{
				StaticCollisionList::EraseEnemyObject(sub_vines[i].get());
			}
		}

		vine_main->Update(V, P);
		sub_vines[0]->Update(V, P);
		sub_vines[1]->Update(V, P);
		sub_vines[2]->Update(V, P);
		collider->World(vine_main->World(), Vector2(1, 0.6f));
		collider->Update(V, P);
	}
}

void FinalMainVine::Render()
{
	if (b_live)
	{
		sub_vines[0]->Render();
		sub_vines[1]->Render();
		sub_vines[2]->Render();
		vine_main->Render();
		//collider->Render();
	}
}

void FinalMainVine::Spawn(Vector2 _position)
{
	b_live = true;
	position = _position;
	vine_main->Position(_position);
	vine_main->Play(0, 16);
}

void FinalMainVine::Die()
{
	b_live = false;
}

bool FinalMainVine::IsLive()
{
	return b_live;
}

void FinalMainVine::AttackPlatform()
{
	int rand = Math::Random(0, 2);
	while (rand == precedence)
		rand = Math::Random(0, 2);
	sub_vines[rand]->Play();
	StaticCollisionList::InsertEnemyObject(sub_vines[rand].get());
	precedence = rand;
}