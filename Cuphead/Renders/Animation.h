#pragma once
//HX Animation기점으로 clip, sprite 스마트포인터 작업 아직 안함
class Animation
{
public:
	Animation();
	Animation(Vector2 _position, Vector2 _scale);
	virtual ~Animation();

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

	void AddClip(Clip* clip);
	void Play(UINT clip_number);
	void Play(UINT clip_number, UINT repeat_start_frame);
	//void Play(UINT clip_number, UINT repeat_start_frame, UINT repeat_end_frame);
	void Stop();
	bool IsPlayEnd(UINT clip_number);

	int CurrentClipNum();
	Clip* CurrentClip();
	Sprite* CurrentSprite();
	Matrix& World();
	void SetWorld(Matrix& world);
	Vector2 TextureSize();
	float ForwardVector();
	
protected:
	Vector2 position;
	Vector2 scale;
	Vector3 rotation;
	vector<Clip*> clips;
	int currentClipNum;
};