#pragma once

class ShootAnim : public Animation
{
public:
	ShootAnim(wstring shaderFile)
	{
		wstring shoot_up = L"Player/Shoot/Up/cuphead_shoot_up.png";
		wstring shoot_up_boil = L"Player/Shoot/Up/cuphead_shoot_up_boil.png";
		wstring shoot_down = L"Player/Shoot/Down/cuphead_shoot_down.png";
		wstring shoot_down_boil = L"Player/Shoot/Down/cuphead_shoot_down_boil.png";
		wstring shoot_straight = L"Player/Shoot/Straight/cuphead_shoot_straight.png";
		wstring shoot_straight_boil = L"Player/Shoot/Straight/cuphead_shoot_straight_boil.png";
		wstring shoot_diagonal_up = L"Player/Shoot/Diagonal Up/cuphead_shoot_diagonal_up.png";
		wstring shoot_diagonal_up_boil = L"Player/Shoot/Diagonal Up/cuphead_shoot_diagonal_up_boil.png";
		wstring shoot_diagonal_down = L"Player/Shoot/Diagonal Down/cuphead_shoot_diagonal_down.png";
		wstring shoot_diagonal_down_boil = L"Player/Shoot/Diagonal Down/cuphead_shoot_diagonal_down_boil.png";

		Clip* clip;
		{	// shoot_up
			clip = new Clip(PlayMode::Loop);
			clip->AddFrame(new Sprite(shoot_up, shaderFile, 0, 0, 108, 172), 0.1f);
			clip->AddFrame(new Sprite(shoot_up, shaderFile, 0, 172, 105, 336), 0.1f);
			clip->AddFrame(new Sprite(shoot_up, shaderFile, 0, 336, 105, 503), 0.1f);
			AddClip(clip);
		}
		{	// shoot_up_boil
			clip = new Clip(PlayMode::Loop);
			clip->AddFrame(new Sprite(shoot_up_boil, shaderFile, 0, 0, 116, 187), 0.1f);
			clip->AddFrame(new Sprite(shoot_up_boil, shaderFile, 0, 187, 116, 373), 0.1f);
			clip->AddFrame(new Sprite(shoot_up_boil, shaderFile, 0, 373, 118, 562), 0.1f);
			AddClip(clip);
		}
		{	// shoot_down
			clip = new Clip(PlayMode::Loop);
			clip->AddFrame(new Sprite(shoot_down, shaderFile, 0, 0, 101, 169), 0.1f);
			clip->AddFrame(new Sprite(shoot_down, shaderFile, 0, 169, 96, 324), 0.1f);
			clip->AddFrame(new Sprite(shoot_down, shaderFile, 0, 324, 98, 483), 0.1f);
			AddClip(clip);
		}
		{	// shoot_down_boil
			clip = new Clip(PlayMode::Loop);
			clip->AddFrame(new Sprite(shoot_down_boil, shaderFile, 0, 0, 112, 181), 0.1f);
			clip->AddFrame(new Sprite(shoot_down_boil, shaderFile, 0, 181, 110, 361), 0.1f);
			clip->AddFrame(new Sprite(shoot_down_boil, shaderFile, 0, 361, 110, 542), 0.1f);
			AddClip(clip);
		}
		{	// shoot_straight
			clip = new Clip(PlayMode::Loop);
			clip->AddFrame(new Sprite(shoot_straight, shaderFile, 0, 0, 126, 150), 0.1f);
			clip->AddFrame(new Sprite(shoot_straight, shaderFile, 0, 150, 127, 307), 0.1f);
			clip->AddFrame(new Sprite(shoot_straight, shaderFile, 0, 307, 118, 460), 0.1f);
			AddClip(clip);
		}
		{	// shoot_straight_boil
			clip = new Clip(PlayMode::Loop);
			clip->AddFrame(new Sprite(shoot_straight_boil, shaderFile, 0, 0, 137, 165), 0.1f);
			clip->AddFrame(new Sprite(shoot_straight_boil, shaderFile, 0, 165, 136, 330), 0.1f);
			clip->AddFrame(new Sprite(shoot_straight_boil, shaderFile, 0, 330, 137, 495), 0.1f);
			AddClip(clip);
		}
		{	// shoot_diagonal_up
			clip = new Clip(PlayMode::Loop);
			clip->AddFrame(new Sprite(shoot_diagonal_up, shaderFile, 0, 0, 126, 150), 0.1f);
			clip->AddFrame(new Sprite(shoot_diagonal_up, shaderFile, 0, 150, 122, 296), 0.1f);
			clip->AddFrame(new Sprite(shoot_diagonal_up, shaderFile, 0, 296, 122, 445), 0.1f);
			AddClip(clip);
		}
		{	// shoot_diagonal_up_boil
			clip = new Clip(PlayMode::Loop);
			clip->AddFrame(new Sprite(shoot_diagonal_up_boil, shaderFile, 0, 0, 138, 164), 0.1f);
			clip->AddFrame(new Sprite(shoot_diagonal_up_boil, shaderFile, 0, 164, 136, 328), 0.1f);
			clip->AddFrame(new Sprite(shoot_diagonal_up_boil, shaderFile, 0, 328, 140, 490), 0.1f);
			AddClip(clip);
		}
		{	// shoot_diagonal_down
			clip = new Clip(PlayMode::Loop);
			clip->AddFrame(new Sprite(shoot_diagonal_down, shaderFile, 0, 0, 117, 159), 0.1f);
			clip->AddFrame(new Sprite(shoot_diagonal_down, shaderFile, 0, 159, 120, 315), 0.1f);
			clip->AddFrame(new Sprite(shoot_diagonal_down, shaderFile, 0, 315, 120, 476), 0.1f);
			AddClip(clip);
		}
		{	// shoot_diagonal_down_boil
			clip = new Clip(PlayMode::Loop);
			clip->AddFrame(new Sprite(shoot_diagonal_down_boil, shaderFile, 0, 0, 130, 171), 0.1f);
			clip->AddFrame(new Sprite(shoot_diagonal_down_boil, shaderFile, 0, 171, 127, 344), 0.1f);
			clip->AddFrame(new Sprite(shoot_diagonal_down_boil, shaderFile, 0, 344, 129, 517), 0.1f);
			AddClip(clip);
		}
	}
};