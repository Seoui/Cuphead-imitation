#pragma once
#include "Generator.h"
#include "Objects/VenusFlytrap.h"
#include "Objects/VenusSeed.h"
#include "Objects/VenusVine.h"

class VenusFlytrapGenerator : public Generator
{
public:
	VenusFlytrapGenerator();
	~VenusFlytrapGenerator() = default;

public:
	void Update(Matrix& V, Matrix& P) override;
	void Render() override;
	void Spawn(int times) override;

public:
	void CupheadPosition(Vector2 _position);

private:
	random_device rd;
	vector<unique_ptr<VenusFlytrap>> flytraps;
	vector<unique_ptr<VenusSeed>> seeds;
	vector<unique_ptr<VenusVine>> vines;
	vector<bool> b_seed_live;
	vector<bool> b_seed_dead;
	vector<bool> b_flytrap_live;
	vector<bool> b_vine_live;
	vector<bool> b_vine_dead;
	const int num_flytrap = 12;
	int spawn_count;
};