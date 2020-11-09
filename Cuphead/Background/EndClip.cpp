#include "stdafx.h"
#include "EndClip.h"

EndClip::EndClip()
{
	wstring shader_file = L"Effect.fx";
	wstring end_texture1 = L"Knockout1.png";
	wstring end_texture2 = L"Knockout2.png";
	end_clip = make_unique<Clip>(PlayMode::End);
	end_clip->AddFrame(new Sprite(end_texture1, shader_file, 1030, 323, 1549, 547), 0.1f);
	end_clip->AddFrame(new Sprite(end_texture2, shader_file, 514, 40, 1028, 260), 0.1f);
	end_clip->AddFrame(new Sprite(end_texture2, shader_file, 1, 332, 517, 552), 0.1f);
	end_clip->AddFrame(new Sprite(end_texture1, shader_file, 1, 763, 517, 984), 0.1f);
	end_clip->AddFrame(new Sprite(end_texture1, shader_file, 1285, 1487, 1800, 1706), 0.1f);
	end_clip->AddFrame(new Sprite(end_texture1, shader_file, 1026, 616, 1545, 836), 0.1f);
	end_clip->AddFrame(new Sprite(end_texture1, shader_file, 1028, 35, 1544, 255), 0.1f);
	end_clip->AddFrame(new Sprite(end_texture1, shader_file, 1028, 35, 1544, 255), 0.1f);
	end_clip->AddFrame(new Sprite(end_texture1, shader_file, 1028, 35, 1544, 255), 0.1f);
	end_clip->AddFrame(new Sprite(end_texture1, shader_file, 1028, 35, 1544, 255), 0.1f);
	end_clip->AddFrame(new Sprite(end_texture1, shader_file, 1028, 35, 1544, 255), 0.1f);

	end_clip->Scale(2.5f, 3.5f);
	end_clip->Position(Vector2(0, -(end_clip->TextureSize().y)* 0.5f));
}

void EndClip::Update(Matrix & V, Matrix & P)
{
	end_clip->Update(V, P);
}

void EndClip::Render()
{
	end_clip->Render();
}

void EndClip::Play()
{
	end_clip->Play(0);
}
