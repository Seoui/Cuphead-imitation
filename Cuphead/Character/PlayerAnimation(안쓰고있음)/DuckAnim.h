#pragma once

class DuckAnim : public Animation
{
public:
	DuckAnim(wstring shaderFile)
	{
		wstring duck = L"Player/Duck/Idle/cuphead_duck.png";
		wstring duck_idle = L"Player/Duck/Idle/cuphead_duck_idle.png";
		wstring duck_turn = L"Player/Duck/Idle/cuphead_duck_turn.png";
		wstring duck_shoot = L"Player/Duck/Shoot/cuphead_duck_shoot.png";
		wstring duck_shoot_boil = L"Player/Duck/Shoot/cuphead_duck_shoot_boil.png";

		Clip* clip;
		{	// duck
			clip = new Clip(PlayMode::Loop);
			clip->AddFrame(new Sprite(duck, shaderFile, 0, 0, 163, 92), 0.1f);
			clip->AddFrame(new Sprite(duck, shaderFile, 0, 92, 144, 214), 0.1f);
			clip->AddFrame(new Sprite(duck, shaderFile, 0, 214, 167, 314), 0.1f);
			clip->AddFrame(new Sprite(duck, shaderFile, 0, 314, 161, 390), 0.1f);
			clip->AddFrame(new Sprite(duck, shaderFile, 0, 390, 164, 470), 0.1f);
			clip->AddFrame(new Sprite(duck, shaderFile, 0, 470, 161, 555), 0.1f);
			clip->AddFrame(new Sprite(duck, shaderFile, 0, 555, 162, 647), 0.1f);
			AddClip(clip);
		}
		{	// duck_idle
			clip = new Clip(PlayMode::Loop);
			clip->AddFrame(new Sprite(duck_idle, shaderFile, 0, 0, 162, 68), 0.1f);
			clip->AddFrame(new Sprite(duck_idle, shaderFile, 0, 68, 164, 137), 0.1f);
			clip->AddFrame(new Sprite(duck_idle, shaderFile, 0, 137, 164, 211), 0.1f);
			clip->AddFrame(new Sprite(duck_idle, shaderFile, 0, 211, 162, 287), 0.1f);
			clip->AddFrame(new Sprite(duck_idle, shaderFile, 0, 287, 162, 367), 0.1f);
			AddClip(clip);
		}
		{	// duck_turn
			clip = new Clip(PlayMode::Loop);
			clip->AddFrame(new Sprite(duck_turn, shaderFile, 0, 0, 168, 75), 0.1f);
			AddClip(clip);
		}
		{	// duck_shoot
			clip = new Clip(PlayMode::Loop);
			clip->AddFrame(new Sprite(duck_shoot, shaderFile, 0, 0, 178, 68), 0.1f);
			clip->AddFrame(new Sprite(duck_shoot, shaderFile, 0, 68, 170, 138), 0.1f);
			clip->AddFrame(new Sprite(duck_shoot, shaderFile, 0, 138, 146, 219), 0.1f);
			AddClip(clip);
		}
		{	// duck_shoot_boil
			clip = new Clip(PlayMode::Loop);
			clip->AddFrame(new Sprite(duck_shoot_boil, shaderFile, 0, 0, 193, 72), 0.1f);
			clip->AddFrame(new Sprite(duck_shoot_boil, shaderFile, 0, 72, 192, 144), 0.1f);
			clip->AddFrame(new Sprite(duck_shoot_boil, shaderFile, 0, 144, 193, 216), 0.1f);
			AddClip(clip);
		}
	}
};

