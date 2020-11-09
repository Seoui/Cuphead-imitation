#pragma once
#include "Generator.h"
#include "Objects/Boomerang.h"

class BoomerangGenerator : public Generator
{
public:
	BoomerangGenerator();
	~BoomerangGenerator() = default;

public:
	void Update(Matrix& V, Matrix& P) override;
	void Render() override;
	void Spawn(int times = 1) override;

private:
	vector<unique_ptr<Boomerang>> boomerangs;
	vector<bool> b_boomerang_live;
	const int num_boomerang = 12;
	int spawn_count;
};