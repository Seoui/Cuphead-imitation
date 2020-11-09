#include "stdafx.h"
#include "Freedom.h"

Freedom::Freedom(float speed)
	: speed(speed)
{}

void Freedom::Update()
{
	if (Key->Press('A'))
	{
		Move(Vector2(-1, 0) * speed);
	}
	else if (Key->Press('D'))
	{
		Move(Vector2(+1, 0) * speed);
	}
	if (Key->Press('W'))
	{
		Move(Vector2(0, +1) * speed);
	}
	else if (Key->Press('S'))
	{
		Move(Vector2(0, -1) * speed);
	}

	__super::Update();
}

void Freedom::Position(float x, float y)
{
	Position(Vector2(x, y));
}

void Freedom::Position(Vector2 & vec)
{
	position = vec;
}

void Freedom::Move(Vector2 translation)
{
	position += translation * Time::Delta();
}
