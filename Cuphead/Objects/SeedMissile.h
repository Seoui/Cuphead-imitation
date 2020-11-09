#pragma once
#include "Object.h"

class SeedMissile
{
public:
	SeedMissile(Vector2 _position);
	~SeedMissile() = default;
	void Update(Matrix& V, Matrix& P);
	void Render();
	void Play();

private:
	unique_ptr<Clip> blue_missile_clip;
	unique_ptr<Clip> purple_missile_clip;
	unique_ptr<Clip> missile_fx;
};