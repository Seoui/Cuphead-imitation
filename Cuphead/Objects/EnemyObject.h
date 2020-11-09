#pragma once
#include "Object.h"

class EnemyObject : public Object
{
public:
	EnemyObject()
		: Object() {}
	EnemyObject(Vector2 _position, Vector2 _scale)
		: Object(_position, _scale) {}
	virtual ~EnemyObject() = default;
};