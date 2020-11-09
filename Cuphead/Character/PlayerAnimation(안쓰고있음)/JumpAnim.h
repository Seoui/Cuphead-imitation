#pragma once
class JumpAnim : public Animation
{
public:
	JumpAnim(wstring shaderFile)
	{
		wstring jump = L"Player/Jump/Cuphead/cuphead_jump.png";
		Clip* clip;
		{	// Jump
			clip = new Clip(PlayMode::Loop);
			clip->AddFrame(new Sprite(jump, shaderFile, 0, 0, 77, 79), 0.1f);
			clip->AddFrame(new Sprite(jump, shaderFile, 0, 79, 77, 186), 0.1f);
			clip->AddFrame(new Sprite(jump, shaderFile, 0, 186, 82, 295), 0.1f);
			clip->AddFrame(new Sprite(jump, shaderFile, 0, 295, 80, 398), 0.1f);
			clip->AddFrame(new Sprite(jump, shaderFile, 0, 398, 81, 475), 0.1f);
			clip->AddFrame(new Sprite(jump, shaderFile, 0, 475, 76, 573), 0.1f);
			clip->AddFrame(new Sprite(jump, shaderFile, 0, 573, 88, 680), 0.1f);
			clip->AddFrame(new Sprite(jump, shaderFile, 0, 680, 86, 784), 0.1f);
			AddClip(clip);
		}
	}
};