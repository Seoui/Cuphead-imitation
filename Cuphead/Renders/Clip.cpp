#include "stdafx.h"
#include "Clip.h"

Frame::Frame(Sprite * image, float time)
{
	Image = image;
	Time = time;
}

Frame::~Frame()
{
	//SAFE_DELETE(Image);
}

Clip::Clip(PlayMode _mode, float _speed)
	: mode(_mode), speed(_speed), length(0.0f),
	framePlayTime(0.0f), clipPlayTime(0.0f),
	bPlay(false), bEnd(false), bRepeat(false), bHide(false),
	curFrameIndex(0), position(0.0f, 0.0f), scale(1.0f, 1.0f), rotation(0.0f, 0.0f, 0.0f),
	repeat_start_frame(-1), repeat_end_frame(-1),
	in_repeat(0), repeat(0)
{
}

Clip::Clip(PlayMode _mode, int _repeat_start_frame, float _speed)
	: mode(_mode), speed(_speed), length(0.0f),
	framePlayTime(0.0f), clipPlayTime(0.0f),
	bPlay(false), bEnd(false), bRepeat(false), bHide(false),
	curFrameIndex(0), position(0.0f, 0.0f), scale(1.0f, 1.0f), rotation(0.0f, 0.0f, 0.0f),
	repeat_start_frame(_repeat_start_frame), repeat_end_frame(-1),
	in_repeat(0), repeat(0)
{
}

Clip::~Clip()
{
	for (Frame* frame : frames)
		SAFE_DELETE(frame);
}

void Clip::AddFrame(Sprite * sprite, float time)
{
	frames.push_back(new Frame(sprite, time));
}

bool Clip::IsPlayEnd()
{
	return bEnd;
}

void Clip::Play(UINT _start_frame)
{
	framePlayTime = 0.0f;
	curFrameIndex = _start_frame;
	bPlay = true;
	bEnd = false;
	bHide = false;
}

void Clip::Play(UINT _start_frame, UINT _repeat_start_frame)
{
	framePlayTime = 0.0f;
	curFrameIndex = _start_frame;
	repeat_start_frame = _repeat_start_frame;
	bPlay = true;
	bEnd = false;
	bHide = false;
}

/*
void Clip::Play(UINT _start_frame, UINT _repeat_start_frame, UINT _repeat_end_frame)
{
	framePlayTime = 0.0f;
	curFrameIndex = _start_frame;
	repeat_start_frame = _repeat_start_frame;
	repeat_end_frame = _repeat_end_frame;
	bPlay = true;
	bEnd = false;
	bHide = false;
}
*/
void Clip::Stop()
{
	bPlay = false;
	bEnd = true;
	curFrameIndex = frames.size() - 1;
}

Matrix& Clip::World()
{
	return frames[curFrameIndex]->Image->World();
}

void Clip::Update(Matrix & V, Matrix & P)
{
	Frame* frame = frames[curFrameIndex];
	
	if (bPlay == true)
	{
		float frameInputTime = frame->Time * speed;
		framePlayTime += Time::Delta();

		if (framePlayTime >= frameInputTime)
		{
			switch (mode)
			{
				case PlayMode::End:
				{
					curFrameIndex++;

					if (curFrameIndex >= frames.size())
					{
						Stop();
					}
				}
				break;
				case PlayMode::Loop:
				{
					//bRepeat = false;
					curFrameIndex++;
					//OPTIMIZATION
					if (curFrameIndex == frames.size())
						bRepeat = true;
					curFrameIndex %= frames.size();
				}
				break;
				case PlayMode::Once:
				{
					curFrameIndex++;
					if (curFrameIndex == frames.size())
					{
						curFrameIndex = 0;
						bHide = true;
					}
				}
				break;
				case PlayMode::RoundLoop:
				{
					if (curFrameIndex == frames.size() || curFrameIndex == 0)
					{
						pm_1 = -pm_1;
					}
					curFrameIndex = curFrameIndex + pm_1;
					curFrameIndex %= frames.size();
				}
			}
			framePlayTime = 0.0f;
		}

		if (curFrameIndex > 0 && curFrameIndex <= frames.size() )
		{
			clipPlayTime += Time::Delta();
		}
	}

	if (bRepeat == true)
	{
		if ((int)curFrameIndex < repeat_start_frame)
			curFrameIndex = repeat_start_frame;
	}

	frames[curFrameIndex]->Image->Scale(scale);
	frames[curFrameIndex]->Image->Rotation(rotation);
	frames[curFrameIndex]->Image->Position(position);
	frames[curFrameIndex]->Image->Update(V, P);
}

void Clip::Render()
{
	
	// PlayMode::Loop 인데 특정 위치에서 Loop가 필요하다면
	/*
	if(repeat_start_frame > -1)
	{
		if ((int)curFrameIndex < repeat_start_frame)
			curFrameIndex = repeat_start_frame;
	}
	*/
	/*
	// PlayMode::Loop 인데 세번째 버전(특정 시작, 특정 종료지점 반복)
	else if (repeat_end_frame > -1)
	{
		if ((int)curFrameIndex < repeat_start_frame)
			curFrameIndex = repeat_start_frame;
		if ((int)curFrameIndex > repeat_end_frame)
			curFrameIndex = repeat_start_frame;
	}
	*/
	// PlayMode::Once에서 bHide를 설정한다,
	// 다른 모드에서는 bHide와 관련없으므로 조건식이 항상 성립한다.
	if(bHide == false)
		frames[curFrameIndex]->Image->Render();
}

Vector2 Clip::TextureSize()
{
	return frames[curFrameIndex]->Image->TextureSize();
}

Sprite * Clip::CurrentSprite()
{
	return frames[curFrameIndex]->Image;
}

float Clip::ClipPlayTime()
{
	if(curFrameIndex == frames.size())
		return clipPlayTime;
	return 0;
}


void Clip::Position(float x, float y)
{
	Position(Vector2(x, y));
}

void Clip::Position(Vector2 vec)
{
	position = vec;
}

Vector2 Clip::Position()
{
	return position;
}

void Clip::Scale(float x, float y)
{
	Scale(Vector2(x, y));
}

void Clip::Scale(Vector2 vec)
{
	scale = vec;
}

Vector2 Clip::Scale()
{
	return scale;
}

void Clip::Rotation(float x, float y, float z)
{
	Rotation(Vector3(x, y, z));
}

void Clip::Rotation(Vector3 & vec)
{
	rotation = vec;
}

Vector3 Clip::Rotation()
{
	return rotation;
}

void Clip::RotationDegree(float x, float y, float z)
{
	RotationDegree(Vector3(x, y, z));
}

void Clip::RotationDegree(Vector3 & vec)
{
	Vector3 temp;
	temp.x = Math::ToRadian(vec.x);
	temp.y = Math::ToRadian(vec.y);
	temp.z = Math::ToRadian(vec.z);

	Rotation(temp);
}

Vector3 Clip::RotationDegree()
{
	Vector3 temp = rotation;
	temp.x = Math::ToDegree(rotation.x);
	temp.y = Math::ToDegree(rotation.y);
	temp.z = Math::ToDegree(rotation.z);

	return temp;
}
