#pragma once

class DashAnim : public Animation
{
public:
	DashAnim(wstring shaderFile)
	{
		wstring dash = L"Player/Dash/Ground/cuphead_dash.png";
		wstring dash_air = L"Player/Dash/Air/cuphead_dash_air.png";

		Clip* clip;
		{	// dash
			clip = new Clip(PlayMode::Loop);
			clip->AddFrame(new Sprite(dash, shaderFile, 0, 0, 102, 132), 0.2f);
			clip->AddFrame(new Sprite(dash, shaderFile, 0, 132, 156, 248), 0.2f);
			clip->AddFrame(new Sprite(dash, shaderFile, 0, 248, 254, 381), 0.2f);
			clip->AddFrame(new Sprite(dash, shaderFile, 0, 381, 273, 514), 0.2f);
			clip->AddFrame(new Sprite(dash, shaderFile, 0, 514, 290, 649), 0.2f);
			clip->AddFrame(new Sprite(dash, shaderFile, 0, 649, 312, 792), 0.2f);
			clip->AddFrame(new Sprite(dash, shaderFile, 0, 792, 326, 947), 0.2f);
			clip->AddFrame(new Sprite(dash, shaderFile, 0, 947, 227, 1110), 0.2f);
			AddClip(clip);
		}
		{	// dash_air
			clip = new Clip(PlayMode::End);
			clip->AddFrame(new Sprite(dash_air, shaderFile, 0, 0, 101, 128), 0.1f);
			clip->AddFrame(new Sprite(dash_air, shaderFile, 0, 128, 154, 250), 0.1f);
			clip->AddFrame(new Sprite(dash_air, shaderFile, 0, 250, 252, 358), 0.1f);
			clip->AddFrame(new Sprite(dash_air, shaderFile, 0, 358, 273, 465), 0.1f);
			clip->AddFrame(new Sprite(dash_air, shaderFile, 0, 465, 290, 575), 0.1f);
			clip->AddFrame(new Sprite(dash_air, shaderFile, 0, 575, 312, 690), 0.1f);
			clip->AddFrame(new Sprite(dash_air, shaderFile, 0, 690, 326, 816), 0.1f);
			clip->AddFrame(new Sprite(dash_air, shaderFile, 0, 816, 226, 951), 0.1f);
			AddClip(clip);
		}
	}
};