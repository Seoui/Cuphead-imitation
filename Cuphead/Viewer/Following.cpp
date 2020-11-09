#include "stdafx.h"
#include "Following.h"

Following::Following(IFollowing * _focus)
	: focus(_focus)
{
}

void Following::Update()
{
	if (focus == nullptr)
		return;

	Vector2 location, size;
	focus->Focus(&location, &size);
	location.x -= (float)Width * 0.5f;
	location.y -= (float)Height * 0.5f;
	location.x += size.x * 0.5f;
	location.y += size.y *0.5f;
	position = location;

	__super::Update();
}

void Following::Change(IFollowing * _focus)
{
	focus = _focus;
}
