#include "stdafx.h"
#include "PlatformC.h"

PlatformC::PlatformC(Vector2 _position, Vector2 _scale)
	: Platform(_position, _scale)
	, right_up(0, 0), left_up(0, 0)
{
	platformC = make_unique<Clip>(PlayMode::Loop);
	platformC->AddFrame(new Sprite(platform_texture, shader_file, 0, 541, 159, 634), 0.1f);
	platformC->AddFrame(new Sprite(platform_texture, shader_file, 0, 634, 160, 725), 0.1f);
	platformC->AddFrame(new Sprite(platform_texture, shader_file, 0, 725, 160, 815), 0.1f);
	platformC->Position(_position);
	platformC->Scale(_scale);

	propellor_pos = Vector2(_position.x + 5, _position.y - 18);
	propellor->Position(propellor_pos);

	shadow_pos = Vector2(_position.x + 5, _position.y - 120);
	shadow_fx->Position(shadow_pos);
	
	Play();
}

void PlatformC::Update(Matrix & V, Matrix & P)
{
	duration += Time::Delta();
	position.y += 0.005f * sin(2 * duration);
	propellor_pos.y += 0.005f * sin(2 * duration);
	if (duration > 100) duration = 0;

	right_up = { position.x - platformC->TextureSize().x * 0.5f,
		position.y + platformC->TextureSize().y - 30.0f };
	left_up = { position.x + platformC->TextureSize().x * 0.5f,
		position.y + platformC->TextureSize().y - 30.0f };
	platformC->Position(position);
	propellor->Position(propellor_pos);
	shadow_fx->Position(shadow_pos);
	platformC->Update(V, P);
	propellor->Update(V, P);
	shadow_fx->Update(V, P);
}

void PlatformC::Render()
{
	propellor->Render();
	platformC->Render();
	shadow_fx->Render();
}

void PlatformC::Play()
{
	platformC->Play(0);
	propellor->Play(0);
	shadow_fx->Play(0);
}

Vector2 PlatformC::RightUpPos()
{
	return right_up;
}

Vector2 PlatformC::LeftUpPos()
{
	return left_up;
}
