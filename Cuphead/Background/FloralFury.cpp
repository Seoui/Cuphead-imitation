#include "stdafx.h"
#include "FloralFury.h"

FloralFury::FloralFury(Vector2 _position)
{
	wstring shader_file = L"Effect.fx";
	main = make_unique<Sprite>(L"Stage/Cuphead_Stage_Floral_Fury.png", shader_file, 15.0f, 1200.0f, 1445.0f, 2015.0f);
	main->Position(Vector2(_position.x, _position.y - (main->TextureSize().y * 0.5f)));
	hill = make_unique<Sprite>(L"Stage/Cuphead_Stage_Floral_Fury.png", shader_file, 0.0f, 670.0f, 1400.0f, 1190.0f);
	hill->Position(Vector2(_position.x, _position.y - (hill->TextureSize().y * 0.5f - 120)));
	sky = make_unique<Sprite>(L"Stage/Cuphead_Stage_Floral_Fury.png", shader_file, 0.0f, 200.0f, 1400.0f, 640.0f);
	sky->Position(Vector2(_position.x, _position.y - (sky->TextureSize().y * 0.5f - 200)));
	sea = make_unique<Sprite>(L"Stage/Cuphead_Stage_Floral_Fury.png", shader_file, 0.0f, 3030.0f, 580.0f, 3160.0f);
	sea->Position(Vector2(_position.x - 70, _position.y - (sea->TextureSize().y * 0.5f + 60)));
	wind1 = make_unique<Sprite>(L"Stage/Cuphead_Stage_Floral_Fury.png", shader_file, 0.0f, 3169.0f, 1400.0f, 3367.0f);
	; wind1->Position(Vector2(_position.x + 1000, _position.y - (wind1->TextureSize().y * 0.5f - 20)));
	wind2 = make_unique<Sprite>(L"Stage/Cuphead_Stage_Floral_Fury.png", shader_file, 0.0f, 3690.0f, 1500.0f, 4030.0f);
	wind2->Position(Vector2(_position.x + 1400, _position.y - (wind2->TextureSize().y * 0.5f - 120)));
}

void FloralFury::Update(Matrix & V, Matrix & P)
{
	Vector2 wind_pos = wind2->Position();
	wind_pos.x -= 0.015f;
	if (wind_pos.x < -1400.0f)
		wind_pos.x = 1400.0f;
	wind2->Position(wind_pos);

	wind_pos = wind1->Position();
	wind_pos.x -= 0.025f;
	if (wind_pos.x < -1200.0f)
		wind_pos.x = 1000.0f;
	wind1->Position(wind_pos);
	
	sky->Update(V, P);
	wind2->Update(V, P);
	wind1->Update(V, P);
	sea->Update(V, P);
	hill->Update(V, P);
	main->Update(V, P);
}

void FloralFury::Render()
{
	sky->Render();
	wind2->Render();
	wind1->Render();
	sea->Render();
	hill->Render();
	main->Render();
}
