#include "stdafx.h"
#include "AcornGenerator.h"

AcornGenerator::AcornGenerator()
	: spawn_count(0)
{
	b_acorn_live.resize(num_acorns);
	acorns.resize(num_acorns);
	for (int i = 0; i < num_acorns; ++i)
	{
		b_acorn_live[i].resize(3);
		acorns[i].resize(3);
	}
	for (int i = 0; i < num_acorns; ++i)
		for(int j = 0; j< 3; ++j)
			acorns[i][j] = make_unique<Acorn>(Vector2(500, 500));
}

void AcornGenerator::Update(Matrix & V, Matrix & P)
{
	for (int i = 0; i < spawn_count; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			b_acorn_live[i][j] = acorns[i][j]->IsLive();

			if (b_acorn_live[i][j])
			{
				acorns[i][j]->Update(V, P);
			}
		}
	}
}

void AcornGenerator::Render()
{
	for (int i = 0; i < spawn_count; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			b_acorn_live[i][j] = acorns[i][j]->IsLive();

			if (b_acorn_live[i][j])
			{
				acorns[i][j]->Render();
			}
		}
	}
}

void AcornGenerator::Spawn(int times)
{
	if (spawn_count >= num_acorns)
	{
		int sc = spawn_count % num_acorns;
		for (int i = 0; i < 3; ++i)
		{
			acorns[sc][i]->Spawn(Vector2(0, static_cast<float>(100 - 100 * i)), static_cast<float>(0.5f + i * 0.8f));
			StaticCollisionList::InsertEnemyObject(acorns[sc][i].get());
		}
	}
	else
	{
		for (int i = 0; i < 3; ++i)
		{
			acorns[spawn_count][i]->Spawn(Vector2(227, static_cast<float>(160 - 87 * i)), static_cast<float>(0.5f + i * 0.8f));
			StaticCollisionList::InsertEnemyObject(acorns[spawn_count][i].get());
		}
	}
	spawn_count++;
}

void AcornGenerator::CupheadPosition(Vector2 _position)
{
	for (int i = 0; i < spawn_count; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			b_acorn_live[i][j] = acorns[i][j]->IsLive();

			if (b_acorn_live[i][j])
			{
				acorns[i][j]->CupheadPosition(_position);
			}
		}
	}
}