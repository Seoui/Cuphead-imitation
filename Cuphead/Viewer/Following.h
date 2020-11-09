#pragma once
#include "Camera.h"
#include "IFollowing.h"

class Following : public Camera
{
public:
	Following(IFollowing* _focus = nullptr);
	~Following() = default;
	void Update() override;

	void Change(IFollowing* _focus);

private:
	IFollowing* focus;
};