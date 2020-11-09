#pragma once

class CupheadAnimation : public Animation
{
public:
	CupheadAnimation();
	~CupheadAnimation();




private:
	vector<Clip*>& whatClips;
	vector<Clip*> idleClips;
	vector<Clip*> runClips;
	vector<Clip*> duckClips;
	vector<Clip*> jumpClips;
	vector<Clip*> aimClips;
};