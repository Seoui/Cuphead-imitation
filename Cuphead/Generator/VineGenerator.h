#pragma once
#include "Generator.h"
#include "Objects/FinalMainVine.h"

class VineGenerator : public Generator
{
public:
	VineGenerator();
	~VineGenerator() = default;

public:
	void Update(Matrix& V, Matrix& P) override;
	void Render() override;
	void Spawn(int times = 1) override;

private:
	vector<unique_ptr<FinalMainVine>> vines;
	vector<bool> b_vine_live;
	const int num_vine = 2;
	int spawn_count;
};