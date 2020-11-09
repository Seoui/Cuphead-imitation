#include "stdafx.h"
#include "SceneManager.h"

SceneManager & SceneManager::Instance()
{
	assert(instance != nullptr);
	return *instance;
}

void SceneManager::Create()
{
	assert(instance == nullptr);
	instance = new SceneManager();
}

void SceneManager::Delete()
{
	SAFE_DELETE(instance);
}
