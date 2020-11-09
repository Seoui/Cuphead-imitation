#include "stdafx.h"
#include "ChomperGenerator.h"

ChomperGenerator::ChomperGenerator()
	: spawn_count(0)
{
	b_seed_live.resize(num_chomper);
	b_seed_dead.resize(num_chomper);
	b_chomper_live.resize(num_chomper);

	for (int i = 0; i < num_chomper; ++i)
	{
		chompers.push_back((move(make_unique<Chomper>(Vector2(500, 500)))));
		seeds.push_back((move(make_unique<ChomperSeed>(Vector2(500, 500)))));
	}
}

void ChomperGenerator::Update(Matrix & V, Matrix & P)
{
	for (int i = 0; i < spawn_count; ++i)
	{
		b_seed_live[i] = seeds[i]->IsLive();
		b_seed_dead[i] = seeds[i]->IsDead();
		b_chomper_live[i] = chompers[i]->IsLive();

		if (b_seed_live[i] && b_seed_dead[i] == false)
		{
			seeds[i]->Update(V, P);
		}
		else if (b_seed_dead[i] && (b_seed_live[i] == false))
		{
			chompers[i]->Spawn(seeds[i]->GrowPosition());
			StaticCollisionList::InsertAttackable(chompers[i].get());
			seeds[i]->Wait();
		}

		if (b_chomper_live[i])
		{
			chompers[i]->Update(V, P);
		}
	}
}

void ChomperGenerator::Render()
{
	for (int i = 0; i < spawn_count; ++i)
	{
		if (b_seed_live[i])
			seeds[i]->Render();
		if (b_chomper_live[i])
			chompers[i]->Render();
	}
}
	
void ChomperGenerator::Spawn(int times)
{
	mt19937 gen(rd());
	for (int i = 0; i < times; ++i)
	{
		uniform_real_distribution<double> dist_x(-600, 100);
		uniform_real_distribution<double> dist_y(900, 1500);
		float rand_x = static_cast<float>(dist_x(gen));
		float rand_y = static_cast<float>(dist_y(gen));
		if (spawn_count >= num_chomper)
		{
			chompers.push_back((move(make_unique<Chomper>(Vector2(500, 500)))));
			seeds.push_back((move(make_unique<ChomperSeed>(Vector2(500, 500)))));
			seeds[spawn_count]->Spawn(Vector2(rand_x, rand_y));
			StaticCollisionList::InsertEnemyObject(seeds[spawn_count].get());
			b_seed_live.push_back(false);
			b_seed_dead.push_back(false);
			b_chomper_live.push_back(false);
		}
		else
		{
			seeds[spawn_count]->Spawn(Vector2(rand_x, rand_y));
			StaticCollisionList::InsertEnemyObject(seeds[spawn_count].get());
		}
		spawn_count++;
	}
}