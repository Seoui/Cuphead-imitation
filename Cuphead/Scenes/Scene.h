#pragma once
#include "stdafx.h"
#include "Viewer/Camera.h"

struct SceneValues
{
	shared_ptr<Camera> MainCamera;
	Matrix Projection;
};

class Scene
{
public:
	Scene(shared_ptr<SceneValues> _values) { values = _values; }
	virtual ~Scene() = default;

	virtual void Update() = 0;
	virtual void Render() = 0;

protected:
	// 생성자에서 이동연산이 이루어지기 때문에 shared_ptr
	shared_ptr<SceneValues> values;
};