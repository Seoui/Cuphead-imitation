#pragma once
#include "Generator.h"
#include "Objects/Chomper.h"
#include "Objects/ChomperSeed.h"

class ChomperGenerator : public Generator
{
public:
	ChomperGenerator();
	~ChomperGenerator() = default;

public:
	void Update(Matrix& V, Matrix& P) override;
	void Render() override;
	void Spawn(int times) override;

private:
	random_device rd;
	vector<unique_ptr<Chomper>> chompers;
	vector<unique_ptr<ChomperSeed>> seeds;
	vector<bool> b_seed_live;
	vector<bool> b_seed_dead;
	vector<bool> b_chomper_live;
	const int num_chomper = 12;
	int spawn_count;
};