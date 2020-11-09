#include "stdafx.h"
#include "SeedMissile.h"

SeedMissile::SeedMissile(Vector2 _position)
{
	wstring shader_file = L"Effect.fx";
	wstring missile_texture = L"Bosses/Cagney Carnation/Firing Seeds/Seed Missiles/Cagney_seed_missile.png";
	blue_missile_clip = make_unique<Clip>(PlayMode::Loop);
	blue_missile_clip->AddFrame(new Sprite(missile_texture, shader_file, 0, 0, 89, 98), 0.1f);
	blue_missile_clip->AddFrame(new Sprite(missile_texture, shader_file, 0, 98, 120, 232), 0.1f);
	blue_missile_clip->AddFrame(new Sprite(missile_texture, shader_file, 0, 232, 102, 346), 0.1f);
	blue_missile_clip->AddFrame(new Sprite(missile_texture, shader_file, 0, 346, 114, 503), 0.1f);
	blue_missile_clip->AddFrame(new Sprite(missile_texture, shader_file, 0, 503, 35, 609), 0.1f);
	blue_missile_clip->AddFrame(new Sprite(missile_texture, shader_file, 0, 609, 22, 756), 0.1f);
	blue_missile_clip->Position(_position);

	purple_missile_clip = make_unique<Clip>(PlayMode::Loop);
	purple_missile_clip->AddFrame(new Sprite(missile_texture, shader_file, 0, 756, 114, 866), 0.1f);
	purple_missile_clip->AddFrame(new Sprite(missile_texture, shader_file, 0, 866, 111, 1022), 0.1f);
	purple_missile_clip->AddFrame(new Sprite(missile_texture, shader_file, 0, 1022, 111, 1117), 0.1f);
	purple_missile_clip->AddFrame(new Sprite(missile_texture, shader_file, 0, 1117, 112, 1258), 0.1f);
	purple_missile_clip->AddFrame(new Sprite(missile_texture, shader_file, 0, 1258, 41, 1366), 0.1f);
	purple_missile_clip->AddFrame(new Sprite(missile_texture, shader_file, 0, 1366, 19, 1471), 0.1f);
	purple_missile_clip->Position(_position);

	missile_fx = make_unique<Clip>(PlayMode::Loop);
	missile_fx->AddFrame(new Sprite(missile_texture, shader_file, 0, 1471, 87, 1509), 0.1f);
	missile_fx->AddFrame(new Sprite(missile_texture, shader_file, 0, 1509, 64, 1536), 0.1f);
	missile_fx->AddFrame(new Sprite(missile_texture, shader_file, 0, 1536, 19, 1553), 0.1f);
	missile_fx->Position(_position);
}

void SeedMissile::Update(Matrix & V, Matrix & P)
{
	blue_missile_clip->Update(V, P);
	purple_missile_clip->Update(V, P);
	missile_fx->Update(V, P);
}

void SeedMissile::Render()
{
	blue_missile_clip->Render();
	purple_missile_clip->Render();
	missile_fx->Render();
}

void SeedMissile::Play()
{
	blue_missile_clip->Play(0);
	purple_missile_clip->Play(0);
	missile_fx->Play(0);
}
