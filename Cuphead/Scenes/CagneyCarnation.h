#pragma once
#include "Scenes/Scene.h"

class CagneyCarnation : public Scene
{
public:
	CagneyCarnation(shared_ptr<SceneValues> values);
	~CagneyCarnation();

public:
	virtual void Update() override;
	virtual void Render() override;

private:
	//unique_ptr<class ScreenFX> screen_fx;
	unique_ptr<class StartClip> start_clip;
	unique_ptr<class EndClip> end_clip;
	unique_ptr<class FloralFury> background;
	unique_ptr<class PlatformA> platformA;
	unique_ptr<class PlatformB> platformB;
	unique_ptr<class PlatformC> platformC;
	unique_ptr<class Cuphead> cuphead;
	unique_ptr<class Cagney> cagney;
	unique_ptr<class Line> floor_line;
	unique_ptr<class Line> cuphead_line;
	vector<unique_ptr<class Line>> platform_lines;

private:
	Vector2 mouse_pos;
	int num_attackable = 0;
	int num_enemy_object = 0;
	bool b_cuphead_cagney = false;
	bool b_cuphead_enemyobject = false;
	bool b_peashots_attackable = false;
	bool b_cuphead_attackable = false;
	bool b_line_collision1 = false;
	bool b_line_collision2 = false;
	bool b_line_collision3 = false;
	bool b_cagney_dead = false;
	bool b_play_once = false;
	const float hit_cool_time = 1.5f;
	float d_hit_cool_time = 0;
};