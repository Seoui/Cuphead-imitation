#include "stdafx.h"
#include "StartClip.h"

StartClip::StartClip()
{
	wstring shader_file = L"Effect.fx";
	wstring ready_texture = L"ready,wallop.png";
	ready = make_unique<Clip>(PlayMode::End);
	ready->AddFrame(new Sprite(ready_texture, shader_file, 590, 75, 945, 260), 0.15f);
	ready->AddFrame(new Sprite(ready_texture, shader_file, 589, 75, 944, 260), 0.15f);
	ready->AddFrame(new Sprite(ready_texture, shader_file, 590, 75, 945, 260), 0.15f);
	ready->AddFrame(new Sprite(ready_texture, shader_file, 591, 75, 946, 260), 0.15f);
	ready->AddFrame(new Sprite(ready_texture, shader_file, 590, 76, 945, 261), 0.15f);
	ready->AddFrame(new Sprite(ready_texture, shader_file, 590, 75, 945, 260), 0.15f);
	ready->AddFrame(new Sprite(ready_texture, shader_file, 590, 74, 945, 259), 0.15f);
//1025, 50, 1550, 265
	ready->AddFrame(new Sprite(ready_texture, shader_file, 1025, 50, 1550, 265), 0.12f);
	ready->AddFrame(new Sprite(ready_texture, shader_file, 1026, 50, 1551, 265), 0.12f);
	ready->AddFrame(new Sprite(ready_texture, shader_file, 1024, 50, 1549, 265), 0.12f);
	ready->AddFrame(new Sprite(ready_texture, shader_file, 1025, 50, 1550, 265), 0.12f);
	ready->AddFrame(new Sprite(ready_texture, shader_file, 1025, 51, 1550, 266), 0.12f);
	ready->AddFrame(new Sprite(ready_texture, shader_file, 1025, 50, 1550, 265), 0.12f);
	ready->AddFrame(new Sprite(ready_texture, shader_file, 1025, 49, 1550, 264), 0.12f);
	
	ready->Scale(2, 2);
	ready->Position(Vector2(0, -(ready->TextureSize().y) * 0.5f));
	ready->Play(0);
}

void StartClip::Update(Matrix & V, Matrix & P)
{
	b_end = ready->IsPlayEnd();
	if(!b_end)
		ready->Update(V, P);
}

void StartClip::Render()
{
	if(!b_end)
		ready->Render();
}
