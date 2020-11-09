#pragma once
#include "Generator.h"
#include "Objects/MiniFlower.h"
#include "Objects/MiniFlowerSeed.h"
#include "Objects/MiniFlowerVine.h"

class MiniFlowerGenerator : public Generator
{
public:
	MiniFlowerGenerator();
	~MiniFlowerGenerator() = default;

public:
	void Update(Matrix& V, Matrix& P) override;
	void Render() override;
	void Spawn(int times) override;

private:
	random_device rd;
	vector<unique_ptr<MiniFlower>> flowers;
	vector<unique_ptr<MiniFlowerSeed>> seeds;
	vector<unique_ptr<MiniFlowerVine>> vines;
	vector<bool> b_seed_live;
	vector<bool> b_seed_dead;
	vector<bool> b_flower_live;
	vector<bool> b_vine_live;
	vector<bool> b_vine_dead;
	const int num_flower = 12;
	int spawn_count;
};