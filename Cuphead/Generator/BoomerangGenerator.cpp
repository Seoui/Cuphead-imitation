#include "stdafx.h"
#include "BoomerangGenerator.h"

BoomerangGenerator::BoomerangGenerator()
	: spawn_count(0)
{
	b_boomerang_live.resize(num_boomerang);

	for (int i = 0; i < num_boomerang; ++i)
	{
		boomerangs.push_back(move(make_unique<Boomerang>(Vector2(500, 500))));
	}
}

void BoomerangGenerator::Update(Matrix & V, Matrix & P)
{
	for (int i = 0; i < spawn_count; ++i)
	{
		b_boomerang_live[i] = boomerangs[i]->IsLive();

		if (b_boomerang_live[i])
			boomerangs[i]->Update(V, P);
	}
}

void BoomerangGenerator::Render()
{
	for (int i = 0; i < spawn_count; ++i)
	{
		b_boomerang_live[i] = boomerangs[i]->IsLive();

		if (b_boomerang_live[i])
			boomerangs[i]->Render();
	}
}

void BoomerangGenerator::Spawn(int times)
{
	if (spawn_count >= num_boomerang)
	{
		int sc = spawn_count % num_boomerang;
		boomerangs[sc]->Spawn(Vector2(0, 100));
		StaticCollisionList::InsertEnemyObject(boomerangs[sc].get());
	}
	else
	{
		boomerangs[spawn_count]->Spawn(Vector2(227, 10));
		StaticCollisionList::InsertEnemyObject(boomerangs[spawn_count].get());
	}
	spawn_count++;
}