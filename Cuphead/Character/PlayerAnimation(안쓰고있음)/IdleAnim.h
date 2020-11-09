#pragma once

class IdleAnim : public Animation
{
public:
	IdleAnim(wstring shaderFile)
	{
		wstring idle = L"Player/Idle/cuphead_idle.png";

		Clip* clip;
		{	// idle
			clip = new Clip(PlayMode::Loop);
			clip->AddFrame(new Sprite(idle, shaderFile, 0, 0, 98, 155), 0.1f);
			clip->AddFrame(new Sprite(idle, shaderFile, 0, 155, 98, 307), 0.1f);
			clip->AddFrame(new Sprite(idle, shaderFile, 0, 307, 98, 456), 0.1f);
			clip->AddFrame(new Sprite(idle, shaderFile, 0, 456, 100, 599), 0.1f);
			clip->AddFrame(new Sprite(idle, shaderFile, 0, 599, 97, 737), 0.1f);
			clip->AddFrame(new Sprite(idle, shaderFile, 0, 456, 100, 599), 0.1f);
			clip->AddFrame(new Sprite(idle, shaderFile, 0, 307, 98, 456), 0.1f);
			clip->AddFrame(new Sprite(idle, shaderFile, 0, 155, 98, 307), 0.1f);
			AddClip(clip);
		}
	}
};