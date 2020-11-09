#pragma once
#include "stdafx.h"

class IFollowing
{
public:
	virtual void Focus(D3DXVECTOR2* position, D3DXVECTOR2* size) = 0;
};