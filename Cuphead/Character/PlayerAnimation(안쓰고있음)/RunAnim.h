#pragma once

class RunAnim : public Animation
{
public: 
	RunAnim(wstring shaderFile)
	{
		wstring run = L"Player/Run/Normal/cuphead_run.png";
		wstring run_turnaround = L"Player/Run/Normal/cuphead_run_turnaround.png";

		Clip* clip;
		{	// Run[1]
			clip = new Clip(PlayMode::Loop);
			clip->AddFrame(new Sprite(run, shaderFile, 0, 0, 135, 155), 0.1f);
			clip->AddFrame(new Sprite(run, shaderFile, 0, 155, 122, 304), 0.1f);
			clip->AddFrame(new Sprite(run, shaderFile, 0, 304, 113, 461), 0.1f);
			clip->AddFrame(new Sprite(run, shaderFile, 0, 461, 109, 623), 0.1f);
			clip->AddFrame(new Sprite(run, shaderFile, 0, 623, 110, 792), 0.1f);
			clip->AddFrame(new Sprite(run, shaderFile, 0, 792, 112, 936), 0.1f);
			clip->AddFrame(new Sprite(run, shaderFile, 0, 936, 122, 1082), 0.1f);
			clip->AddFrame(new Sprite(run, shaderFile, 0, 1082, 130, 1228), 0.1f);
			clip->AddFrame(new Sprite(run, shaderFile, 0, 1228, 122, 1378), 0.1f);
			clip->AddFrame(new Sprite(run, shaderFile, 0, 1378, 114, 1524), 0.1f);
			clip->AddFrame(new Sprite(run, shaderFile, 0, 1524, 113, 1673), 0.1f);
			clip->AddFrame(new Sprite(run, shaderFile, 0, 1673, 115, 1823), 0.1f);
			clip->AddFrame(new Sprite(run, shaderFile, 0, 1823, 120, 1968), 0.1f);
			clip->AddFrame(new Sprite(run, shaderFile, 0, 1968, 118, 2110), 0.1f);
			clip->AddFrame(new Sprite(run, shaderFile, 0, 2110, 128, 2254), 0.1f);
			clip->AddFrame(new Sprite(run, shaderFile, 0, 2254, 137, 2407), 0.1f);
			AddClip(clip);
		}
		{	// Run_turn_around[2]
			clip = new Clip(PlayMode::Loop);
			clip->AddFrame(new Sprite(run_turnaround, shaderFile, 0, 0, 132, 164), 0.1f);
			clip->AddFrame(new Sprite(run_turnaround, shaderFile, 0, 164, 125, 328), 0.1f);
			AddClip(clip);
		}
	}
};