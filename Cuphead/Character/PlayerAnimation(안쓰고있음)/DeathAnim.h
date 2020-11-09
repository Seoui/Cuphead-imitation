#pragma once

class DeathAnim : public Animation
{
public:
	DeathAnim(wstring shaderFile)
	{
		wstring death_body = L"Player/Death/cuphead_death_body.png";

		Clip* clip;
		{	// death_body
			clip = new Clip(PlayMode::Loop);
			clip->AddFrame(new Sprite(death_body, shaderFile, 0, 0, 152, 90), 0.1f);
			clip->AddFrame(new Sprite(death_body, shaderFile, 0, 90, 172, 196), 0.1f);
			clip->AddFrame(new Sprite(death_body, shaderFile, 0, 196, 165, 295), 0.1f);
			clip->AddFrame(new Sprite(death_body, shaderFile, 0, 295, 157, 388), 0.1f);
			clip->AddFrame(new Sprite(death_body, shaderFile, 0, 388, 158, 480), 0.1f);
			clip->AddFrame(new Sprite(death_body, shaderFile, 0, 480, 151, 568), 0.1f);
			clip->AddFrame(new Sprite(death_body, shaderFile, 0, 568, 148, 657), 0.1f);
			clip->AddFrame(new Sprite(death_body, shaderFile, 0, 657, 149, 743), 0.1f);
			clip->AddFrame(new Sprite(death_body, shaderFile, 0, 743, 147, 827), 0.1f);
			clip->AddFrame(new Sprite(death_body, shaderFile, 0, 827, 146, 912), 0.1f);
			clip->AddFrame(new Sprite(death_body, shaderFile, 0, 912, 146, 999), 0.1f);
			clip->AddFrame(new Sprite(death_body, shaderFile, 0, 999, 140, 1085), 0.1f);
			clip->AddFrame(new Sprite(death_body, shaderFile, 0, 1085, 137, 1166), 0.1f);
			clip->AddFrame(new Sprite(death_body, shaderFile, 0, 1166, 138, 1247), 0.1f);
			clip->AddFrame(new Sprite(death_body, shaderFile, 0, 1247, 136, 1327), 0.1f);
			clip->AddFrame(new Sprite(death_body, shaderFile, 0, 1327, 126, 1407), 0.1f);
			AddClip(clip);
		}
	}
};