#include "stdafx.h"
#include "FinalSubVine.h"

FinalSubVine::FinalSubVine()
{
	wstring vines = L"Bosses/Cagney Carnation/Final Form/Vines/Final_Vine.png";
	Sprite* frame1_1 = new Sprite(vines, shader_file, 0, 3650, 74, 3722);
	Sprite* frame2_1 = new Sprite(vines, shader_file, 0, 3722, 105, 3808);
	Sprite* frame3_1 = new Sprite(vines, shader_file, 0, 3808, 123, 3964);
	Sprite* frame4_1 = new Sprite(vines, shader_file, 0, 3964, 125, 4143);
	Sprite* frame5_1 = new Sprite(vines, shader_file, 0, 4143, 139, 4341);
	Sprite* frame6_1 = new Sprite(vines, shader_file, 0, 4341, 117, 4563);
	Sprite* frame7_1 = new Sprite(vines, shader_file, 0, 4563, 122, 4804);
	Sprite* frame8_1 = new Sprite(vines, shader_file, 0, 4804, 120, 5037);
	Sprite* frame9_1 = new Sprite(vines, shader_file, 0, 5037, 121, 5280);
	Sprite* frame10_1 = new Sprite(vines, shader_file, 0, 5280, 121, 5529);
	Sprite* frame11_1 = new Sprite(vines, shader_file, 0, 5529, 122, 5776);
	Sprite* frame12_1 = new Sprite(vines, shader_file, 0, 5776, 126, 6037);
	Sprite* frame13_1 = new Sprite(vines, shader_file, 0, 6037, 127, 6316);
	Sprite* frame14_1 = new Sprite(vines, shader_file, 0, 6316, 129, 6645);
	Sprite* frame15_1 = new Sprite(vines, shader_file, 0, 6645, 142, 7001);
	Sprite* frame16_1 = new Sprite(vines, shader_file, 0, 7001, 143, 7414);
	Sprite* frame17_1 = new Sprite(vines, shader_file, 0, 7414, 164, 7868);
	Sprite* frame18_1 = new Sprite(vines, shader_file, 0, 7868, 159, 8353);
	Sprite* frame19_1 = new Sprite(vines, shader_file, 0, 8353, 160, 8836);
	Sprite* frame20_1 = new Sprite(vines, shader_file, 0, 8836, 159, 9323);
	Sprite* frame21_1 = new Sprite(vines, shader_file, 0, 9323, 162, 9807);
	vine_platform = make_unique<Clip>(PlayMode::End);
	vine_platform->AddFrame(frame1_1, 0.07f);
	vine_platform->AddFrame(frame2_1, 0.07f);
	vine_platform->AddFrame(frame3_1, 0.07f);
	vine_platform->AddFrame(frame4_1, 0.07f);
	vine_platform->AddFrame(frame5_1, 0.07f);
	vine_platform->AddFrame(frame6_1, 0.07f);
	vine_platform->AddFrame(frame7_1, 0.07f);
	vine_platform->AddFrame(frame8_1, 0.07f);
	vine_platform->AddFrame(frame9_1, 0.07f);
	vine_platform->AddFrame(frame10_1, 0.11f);
	vine_platform->AddFrame(frame11_1, 0.11f);
	vine_platform->AddFrame(frame12_1, 0.11f);
	vine_platform->AddFrame(frame13_1, 0.07f);
	vine_platform->AddFrame(frame14_1, 0.07f);
	vine_platform->AddFrame(frame15_1, 0.07f);
	vine_platform->AddFrame(frame16_1, 0.07f);
	vine_platform->AddFrame(frame17_1, 0.07f);
	vine_platform->AddFrame(frame18_1, 0.07f);
	vine_platform->AddFrame(frame19_1, 0.07f);
	vine_platform->AddFrame(frame20_1, 0.07f);
	vine_platform->AddFrame(frame21_1, 0.07f);
	vine_platform->AddFrame(frame20_1, 0.07f);
	vine_platform->AddFrame(frame19_1, 0.07f);
	vine_platform->AddFrame(frame18_1, 0.07f);
	vine_platform->AddFrame(frame17_1, 0.07f);
	vine_platform->AddFrame(frame16_1, 0.07f);
	vine_platform->AddFrame(frame15_1, 0.07f);
	vine_platform->AddFrame(frame14_1, 0.07f);
	vine_platform->AddFrame(frame13_1, 0.07f);
	vine_platform->AddFrame(frame12_1, 0.07f);
	vine_platform->AddFrame(frame11_1, 0.07f);
	vine_platform->AddFrame(frame10_1, 0.07f);
	vine_platform->AddFrame(frame9_1, 0.07f);
	vine_platform->AddFrame(frame8_1, 0.07f);
	vine_platform->AddFrame(frame7_1, 0.07f);
	vine_platform->AddFrame(frame6_1, 0.07f);
	vine_platform->AddFrame(frame5_1, 0.07f);
	vine_platform->AddFrame(frame4_1, 0.07f);
	vine_platform->AddFrame(frame3_1, 0.07f);
	vine_platform->AddFrame(frame2_1, 0.07f);
	vine_platform->AddFrame(frame1_1, 0.07f);
}

void FinalSubVine::Update(Matrix & V, Matrix & P)
{
	vine_platform->Position(position);
	vine_platform->Update(V, P);
	collider->World(vine_platform->World(), Vector2(0.5f, 0.7f));
	collider->Update(V, P);
}

void FinalSubVine::Render()
{
	vine_platform->Render();
	//collider->Render();
}

void FinalSubVine::Play()
{
	vine_platform->Play(0);
}
