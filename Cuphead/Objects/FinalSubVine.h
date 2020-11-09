#pragma once
#include "EnemyObject.h"

class FinalSubVine : public EnemyObject
{
public:
	FinalSubVine();
	~FinalSubVine() = default;

public:
	void Update(Matrix& V, Matrix& P) override;
	void Render() override;

public:
	void Play();
	bool IsPlayEnd() { return vine_platform->IsPlayEnd(); }
	Matrix& World() { return vine_platform->World(); }
	int CurrentFrame() { return vine_platform->CurrentFrame(); }

private:
	unique_ptr<Clip> vine_platform;
};