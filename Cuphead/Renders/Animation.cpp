#include "stdafx.h"
#include "Animation.h"
#include "Systems/Time.h"

Animation::Animation()
	: currentClipNum(-1),
	  position(0.0f, 0.0f), scale(1.0f, 1.0f), rotation(0.0f, 0.0f, 0.0f)
{
}

Animation::Animation(Vector2 _position, Vector2 _scale)
	: currentClipNum(-1),
	  position(_position), scale(_scale), rotation(0.0f, 0.0f, 0.0f)
{
}

Animation::~Animation()
{
	for (Clip* clip : clips)
		SAFE_DELETE(clip);
}

void Animation::AddClip(Clip * clip)
{
	clips.push_back(clip);
}

void Animation::Play(UINT clip_number)
{
	// 같은 키를 여러번 입력했을 때 애니메이션이 처음부터 재생하면 안된다
	// 그런데 애니메이션이 이미 종료된 상황이면 재생 할 수 있어야 함
	//HX 아래 주석부분 다시 연구해서 생각해보길 정확하게 이 코드가
	// 어떤 상황에서 필요한지 모르겠음
	/*
	if(currentClipNum != -1)
		if (clips[currentClipNum]->IsPlayEnd())
			currentClipNum = -1;
	*/

	if (clip_number == currentClipNum)
		return;

	// 현재 clipNumber는 UINT type임
	// int -1은 UINT 입장에서 매우 큰 수이고 
	// 아래 if 문의 조건은 clipNumber에 큰수가 오지 않는한 실행되지 않음.
	if (clip_number > -1)
		clips[currentClipNum]->Stop();

	currentClipNum = clip_number;
	clips[currentClipNum]->Play(0);
}

void Animation::Play(UINT clip_number, UINT repeat_start_frame)
{
	if (clip_number == currentClipNum)
		return;
	if (clip_number > -1)
		clips[currentClipNum]->Stop();
	currentClipNum = clip_number;
	clips[currentClipNum]->Play(0, repeat_start_frame);
}

/*
void Animation::Play(UINT clip_number, UINT repeat_start_frame, UINT repeat_end_frame)
{
	if (clip_number == currentClipNum)
		return;
	if (clip_number > -1)
		clips[currentClipNum]->Stop();
	currentClipNum = clip_number;
	clips[currentClipNum]->Play(0, repeat_start_frame, repeat_end_frame);
}
*/
void Animation::Stop()
{
	if (currentClipNum > -1)
		clips[currentClipNum]->Stop();
}

bool Animation::IsPlayEnd(UINT clip_number)
{
	return clips[clip_number]->IsPlayEnd();
}

void Animation::Position(float x, float y)
{
	Position(Vector2(x, y));
}

void Animation::Position(Vector2 vec)
{
	position = vec;
}

Vector2 Animation::Position()
{
	return position;
}

void Animation::Scale(float x, float y)
{
	Scale(Vector2(x, y));
}

void Animation::Scale(Vector2 vec)
{
	scale = vec;
}

Vector2 Animation::Scale()
{
	return scale;
}

void Animation::Rotation(float x, float y, float z)
{
	Rotation(Vector3(x, y, z));
}

void Animation::Rotation(Vector3 & vec)
{
	rotation = vec;
}

Vector3 Animation::Rotation()
{
	return rotation;
}

void Animation::RotationDegree(float x, float y, float z)
{
	RotationDegree(Vector3(x, y, z));
}

void Animation::RotationDegree(Vector3 & vec)
{
	Vector3 temp;
	temp.x = Math::ToRadian(vec.x);
	temp.y = Math::ToRadian(vec.y);
	temp.z = Math::ToRadian(vec.z);

	Rotation(temp);
}

Vector3 Animation::RotationDegree()
{
	Vector3 temp = Rotation();
	temp.x = Math::ToDegree(rotation.x);
	temp.y = Math::ToDegree(rotation.y);
	temp.z = Math::ToDegree(rotation.z);

	return temp;
}

Vector2 Animation::TextureSize()
{
	if (currentClipNum < 0)
		return Vector2(0, 0);

	return clips[currentClipNum]->TextureSize();
}

void Animation::Update(Matrix & V, Matrix & P)
{
	if (currentClipNum < 0)
		return;

	clips[currentClipNum]->Scale(scale);
	clips[currentClipNum]->Rotation(rotation);
	clips[currentClipNum]->Position(position);
	clips[currentClipNum]->Update(V, P);
}

void Animation::Render()
{
	if (currentClipNum < 0)
		return;

	clips[currentClipNum]->Render();
}

Matrix& Animation::World()
{
	return CurrentClip()->CurrentSprite()->World();
}

void Animation::SetWorld(Matrix & world)
{
	CurrentClip()->CurrentSprite()->SetWorld(world);
}

int Animation::CurrentClipNum()
{
	return currentClipNum;
}

Clip * Animation::CurrentClip()
{
	if(currentClipNum<0)
		return nullptr;

	return clips[currentClipNum];
}

Sprite * Animation::CurrentSprite()
{
	return CurrentClip()->CurrentSprite();
}

float Animation::ForwardVector()
{
	return CurrentSprite()->ForwardVector();
}
