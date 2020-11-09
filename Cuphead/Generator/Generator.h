#pragma once

class Generator
{
public:
	virtual ~Generator() = default;
	virtual void Update(Matrix& V, Matrix& P) = 0;
	virtual void Render() = 0;
	virtual void Spawn(int count = 1) = 0;
};