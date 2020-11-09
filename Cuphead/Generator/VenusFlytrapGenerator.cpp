#include "stdafx.h"
#include "VenusFlytrapGenerator.h"

VenusFlytrapGenerator::VenusFlytrapGenerator()
	: spawn_count(0)
{
	b_seed_live.resize(num_flytrap);
	b_seed_dead.resize(num_flytrap);
	b_flytrap_live.resize(num_flytrap);
	b_vine_live.resize(num_flytrap);
	b_vine_dead.resize(num_flytrap);

	for (int i = 0; i < num_flytrap; ++i)
	{
		flytraps.push_back(move(make_unique<VenusFlytrap>(Vector2(500, 500))));
		seeds.push_back(move(make_unique<VenusSeed>(Vector2(500, 500))));
		vines.push_back(move(make_unique<VenusVine>(Vector2(500, 500))));
	}
}

void VenusFlytrapGenerator::Update(Matrix & V, Matrix & P)
{
	for (int i = 0; i < spawn_count; ++i)
	{
		b_seed_live[i] = seeds[i]->IsLive();
		b_seed_dead[i] = seeds[i]->IsDead();
		b_flytrap_live[i] = flytraps[i]->IsLive();
		b_vine_live[i] = vines[i]->IsLive();
		b_vine_dead[i] = vines[i]->IsDead();

		if (b_seed_live[i] && b_seed_dead[i] == false)
		{
			seeds[i]->Update(V, P);
		}
		else if (b_seed_dead[i] && b_seed_live[i] == false)
		{
			vines[i]->Spawn(seeds[i]->GrowPosition());
			seeds[i]->Wait();
		}

		if (b_vine_live[i] && b_vine_dead[i] == false)
		{
			vines[i]->Update(V, P);
			if (vines[i]->IsGrow())
			{
				flytraps[i]->Spawn(vines[i]->Position());
				StaticCollisionList::InsertAttackable(flytraps[i].get());
				vines[i]->Wait();
			}
		}

		if (b_flytrap_live[i])
		{
			flytraps[i]->Update(V, P);
		}
	}
}

void VenusFlytrapGenerator::Render()
{
	for (int i = 0; i < spawn_count; ++i)
	{
		if (b_seed_live[i])
			seeds[i]->Render();
		if (b_vine_live[i])
			vines[i]->Render();
		if (b_flytrap_live[i])
			flytraps[i]->Render();
	}
}

void VenusFlytrapGenerator::Spawn(int times)
{
	mt19937 gen(rd());
	for (int i = 0; i < times; ++i)
	{
		uniform_real_distribution<double> dist_x(-600, 200);
		uniform_real_distribution<double> dist_y(900, 1300);
		float rand_x = static_cast<float>(dist_x(gen));
		float rand_y = static_cast<float>(dist_y(gen));
		if (spawn_count >= num_flytrap)
		{
			flytraps.push_back((move(make_unique<VenusFlytrap>(Vector2(500, 500)))));
			seeds.push_back((move(make_unique<VenusSeed>(Vector2(500, 500)))));
			vines.push_back((move(make_unique<VenusVine>(Vector2(500, 500)))));
			seeds[spawn_count]->Spawn(Vector2(rand_x, rand_y));
			StaticCollisionList::InsertEnemyObject(seeds[spawn_count].get());
			b_seed_live.push_back(false);
			b_seed_dead.push_back(false);
			b_flytrap_live.push_back(false);
			b_vine_live.push_back(false);
			b_vine_dead.push_back(false);
		}
		else
		{
			seeds[spawn_count]->Spawn(Vector2(rand_x, rand_y));
			StaticCollisionList::InsertEnemyObject(seeds[spawn_count].get());
		}
		spawn_count++;
	}
}

void VenusFlytrapGenerator::CupheadPosition(Vector2 _position)
{
	for (int i = 0; i < spawn_count; ++i)
	{
		b_flytrap_live[i] = flytraps[i]->IsLive();

		if (b_flytrap_live[i])
		{
			flytraps[i]->CupheadPosition(_position);
		}
	}
}