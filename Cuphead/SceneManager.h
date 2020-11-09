#pragma once

class SceneManager
{
public:
	static SceneManager& Instance();
	static void Create();
	static void Delete();

private:
	SceneManager();
	~SceneManager() = default;

private:
	static SceneManager* instance;
};