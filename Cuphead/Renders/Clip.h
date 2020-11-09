#pragma once

enum class PlayMode 
{ 
	End = 0, Loop, Once, 
	RoundLoop
};

struct Frame
{
	Sprite* Image;
	float Time;

	Frame(Sprite* image, float time);
	~Frame();
};

class Clip
{
public:
	Clip(PlayMode mode = PlayMode::End, float speed = 1.0f);
	Clip(PlayMode mode, int repeat_start_frame, float speed = 1.0f);
	~Clip();

	void Update(Matrix& V, Matrix& P);
	void Render();

	void Position(float x, float y);
	void Position(Vector2 vec);
	Vector2 Position();
	void Scale(float x, float y);
	void Scale(Vector2 vec);
	Vector2 Scale();
	void Rotation(float x, float y, float z);
	void Rotation(Vector3& vec);
	Vector3 Rotation();
	void RotationDegree(float x, float y, float z);
	void RotationDegree(Vector3& vec);
	Vector3 RotationDegree();

	void AddFrame(Sprite* sprite, float time);
	void Play(UINT start_frame);
	void Play(UINT start_frame, UINT repeat_start_frame);
	//void Play(UINT start_frame, UINT repeat_start_frame, UINT repeat_end_frame);

	bool IsPlayEnd();
	void Stop();
	Matrix& World();
	Sprite* CurrentSprite();
	Vector2 TextureSize();
	float ClipPlayTime();
	void setHide(bool val) { bHide = val; }
	UINT CurrentFrame() { return curFrameIndex; }

private:
	vector<Frame*> frames;
	Vector2 position;
	Vector2 scale;
	Vector3 rotation;
	PlayMode mode;
	float speed;
	float length;
	float framePlayTime;
	float clipPlayTime;
	float repeat = 0;
	float in_repeat = 0;
	bool bPlay;
	bool bEnd;
	bool bRepeat;
	bool bHide;
	UINT curFrameIndex;
	int repeat_start_frame;
	int repeat_end_frame;
	int pm_1 = -1;
};