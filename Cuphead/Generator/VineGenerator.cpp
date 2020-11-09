#include "stdafx.h"
#include "VineGenerator.h"

VineGenerator::VineGenerator()
	: spawn_count(0)
{
	b_vine_live.resize(num_vine);

	for (int i = 0; i < num_vine; ++i)
	{
		vines.push_back(move(make_unique<FinalMainVine>(Vector2(500, 500))));
	}
}

void VineGenerator::Update(Matrix & V, Matrix & P)
{
	for (int i = 0; i < spawn_count; ++i)
	{
		b_vine_live[i] = vines[i]->IsLive();

		if (b_vine_live[i])
			vines[i]->Update(V, P);
	}
}

void VineGenerator::Render()
{
	for (int i = 0; i < spawn_count; ++i)
	{
		b_vine_live[i] = vines[i]->IsLive();

		if (b_vine_live[i])
			vines[i]->Render();
	}
}

void VineGenerator::Spawn(int times)
{
	if (spawn_count >= num_vine)
	{
		int sc = spawn_count % num_vine;
		vines[sc]->Spawn(Vector2(0, 100));
		StaticCollisionList::InsertEnemyObject(vines[sc].get());
	}
	else
	{
		vines[spawn_count]->Spawn(Vector2(-200, -265));
		StaticCollisionList::InsertEnemyObject(vines[spawn_count].get());
	}
	spawn_count++;
}