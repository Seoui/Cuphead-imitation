#include "stdafx.h"
#include "Camera.h"

Camera::Camera()
	: position(0, 0)
{
	D3DXMatrixIdentity(&view);
}

void Camera::Update()
{
	Vector3 eye = Vector3(position.x - (Width * 0.5f), position.y - (Height * 0.5f), 0.0f);
	Vector3 at(0, 0, 1);
	Vector3 up(0, 1, 0);
	D3DXMatrixLookAtLH(&view, &eye, &(eye + at), &up);
}
