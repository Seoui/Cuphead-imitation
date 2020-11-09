#include "stdafx.h"
#include "PollenGenerator.h"

PollenGenerator::PollenGenerator()
	: spawn_count(0)
{
	b_pollen_live.resize(num_pollen);

	for (int i = 0; i < num_pollen; ++i)
	{
		pollens.push_back(make_unique<Pollen>(Vector2(500, 500)));
	}
}

void PollenGenerator::Update(Matrix & V, Matrix & P)
{
	for (int i = 0; i < spawn_count; ++i)
	{
		b_pollen_live[i] = pollens[i]->IsLive();

		if (b_pollen_live[i])
			pollens[i]->Update(V, P);
	}
}

void PollenGenerator::Render()
{
	for (int i = 0; i < spawn_count; ++i)
	{
		b_pollen_live[i] = pollens[i]->IsLive();

		if (b_pollen_live[i])
			pollens[i]->Render();
	}
}

void PollenGenerator::Spawn(int times)
{
	if (spawn_count >= num_pollen)
	{
		int sc = spawn_count % num_pollen;
		pollens[sc]->Spawn(Vector2(0, 100));
		StaticCollisionList::InsertEnemyObject(pollens[sc].get());
	}
	else
	{
		pollens[spawn_count]->Spawn(Vector2(227, 10));
		StaticCollisionList::InsertEnemyObject(pollens[spawn_count].get());
	}
	spawn_count++;
}