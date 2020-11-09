#pragma once
#include "Generator.h"
#include "Objects/Pollen.h"

class PollenGenerator : public Generator
{
public:
	PollenGenerator();
	~PollenGenerator() = default;
	
public:
	void Update(Matrix& V, Matrix& P) override;
	void Render() override;
	void Spawn(int times = 1) override;

private:
	vector<unique_ptr<Pollen>> pollens;
	vector<bool> b_pollen_live;
	const int num_pollen = 12;
	int spawn_count;
};