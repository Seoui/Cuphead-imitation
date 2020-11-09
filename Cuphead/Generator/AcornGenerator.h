#pragma once
#include "Generator.h"
#include "Objects/Acorn.h"

class AcornGenerator : public Generator
{
public:
	AcornGenerator();
	~AcornGenerator() = default;

public:
	void Update(Matrix& V, Matrix& P) override;
	void Render() override;
	void Spawn(int times = 1) override;

public:
	void CupheadPosition(Vector2 _position);

private:
	vector<vector<unique_ptr<Acorn>>> acorns;
	vector<vector<bool>> b_acorn_live;
	const int num_acorns = 12;
	int spawn_count;
};