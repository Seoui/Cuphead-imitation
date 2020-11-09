#pragma once
//#include "stdafx.h"

class AimAnim : public Animation
{
public:
	AimAnim(wstring shaderFile)
	{
		wstring aim_up = L"Player/Aim/Up/cuphead_aim_up.png";
		wstring aim_down = L"Player/Aim/Down/cuphead_aim_down.png";
		wstring aim_straight = L"Player/Aim/Straight/cuphead_aim_straight.png";
		wstring aim_diagonal_up = L"Player/Aim/Diagonal Up/cuphead_aim_diagonal_up.png";
		wstring aim_diagonal_down = L"Player/Aim/Diagonal Down/cuphead_aim_diagonal_down.png";

		unique_ptr<Clip> clip;
		{	// up
			clip = make_unique<Clip>(PlayMode::Loop);
			clip->AddFrame(new Sprite(aim_up, shaderFile, 0, 0, 106, 175), 0.1f);
			clip->AddFrame(new Sprite(aim_up, shaderFile, 0, 175, 108, 349), 0.1f);
			clip->AddFrame(new Sprite(aim_up, shaderFile, 0, 349, 106, 517), 0.1f);
			clip->AddFrame(new Sprite(aim_up, shaderFile, 0, 517, 107, 681), 0.1f);
			clip->AddFrame(new Sprite(aim_up, shaderFile, 0, 681, 105, 843), 0.1f);
			AddClip(clip.get());
		}
		{	// down
			clip = make_unique<Clip>(PlayMode::Loop);
			clip->AddFrame(new Sprite(aim_down, shaderFile, 0, 0, 99, 168), 0.1f);
			clip->AddFrame(new Sprite(aim_down, shaderFile, 0, 168, 98, 333), 0.1f);
			clip->AddFrame(new Sprite(aim_down, shaderFile, 0, 333, 103, 495), 0.1f);
			clip->AddFrame(new Sprite(aim_down, shaderFile, 0, 495, 99, 654), 0.1f);
			clip->AddFrame(new Sprite(aim_down, shaderFile, 0, 654, 100, 806), 0.1f);
			AddClip(clip.get());
		}
		{	// straight
			clip = make_unique<Clip>(PlayMode::Loop);
			clip->AddFrame(new Sprite(aim_straight, shaderFile, 0, 0, 129, 152), 0.1f);
			clip->AddFrame(new Sprite(aim_straight, shaderFile, 0, 152, 133, 313), 0.1f);
			clip->AddFrame(new Sprite(aim_straight, shaderFile, 0, 313, 134, 469), 0.1f);
			clip->AddFrame(new Sprite(aim_straight, shaderFile, 0, 469, 130, 610), 0.1f);
			clip->AddFrame(new Sprite(aim_straight, shaderFile, 0, 610, 131, 746), 0.1f);
			AddClip(clip.get());
		}
		{	// aim_diagonal_up
			clip = make_unique<Clip>(PlayMode::Loop);
			clip->AddFrame(new Sprite(aim_diagonal_up, shaderFile, 0, 0, 129, 151), 0.1f);
			clip->AddFrame(new Sprite(aim_diagonal_up, shaderFile, 0, 151, 127, 299), 0.1f);
			clip->AddFrame(new Sprite(aim_diagonal_up, shaderFile, 0, 299, 128, 443), 0.1f);
			clip->AddFrame(new Sprite(aim_diagonal_up, shaderFile, 0, 443, 129, 583), 0.1f);
			clip->AddFrame(new Sprite(aim_diagonal_up, shaderFile, 0, 583, 126, 716), 0.1f);
			AddClip(clip.get());
		}
		{	// aim_diagonal_down
			clip = make_unique<Clip>(PlayMode::Loop);
			clip->AddFrame(new Sprite(aim_diagonal_down, shaderFile, 0, 0, 118, 163), 0.1f);
			clip->AddFrame(new Sprite(aim_diagonal_down, shaderFile, 0, 163, 117, 321), 0.1f);
			clip->AddFrame(new Sprite(aim_diagonal_down, shaderFile, 0, 321, 117, 477), 0.1f);
			clip->AddFrame(new Sprite(aim_diagonal_down, shaderFile, 0, 477, 116, 624), 0.1f);
			clip->AddFrame(new Sprite(aim_diagonal_down, shaderFile, 0, 624, 116, 766), 0.1f);
			AddClip(clip.get());
		}
	}
};