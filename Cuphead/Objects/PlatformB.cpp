#include "stdafx.h"
#include "PlatformB.h"

PlatformB::PlatformB(Vector2 _position, Vector2 _scale)
	: Platform(_position, _scale)
	, right_up(0, 0), left_up(0, 0)
{
	platformB = make_unique<Clip>(PlayMode::Loop);
	platformB->AddFrame(new Sprite(platform_texture, shader_file, 0, 268, 160, 360), 0.1f);
	platformB->AddFrame(new Sprite(platform_texture, shader_file, 0, 360, 160, 450), 0.1f);
	platformB->AddFrame(new Sprite(platform_texture, shader_file, 0, 450, 160, 541), 0.1f);
	platformB->Position(_position);
	platformB->Scale(_scale);

	propellor_pos = Vector2(_position.x + 5, _position.y - 18);
	propellor->Position(propellor_pos);

	shadow_pos = Vector2(_position.x + 5, _position.y - 120);
	shadow_fx->Position(shadow_pos);
	
	Play();
}

void PlatformB::Update(Matrix & V, Matrix & P)
{
	duration += Time::Delta();
	position.y += 0.005f * cos(2 * duration);
	propellor_pos.y += 0.005f * cos(2 * duration);
	if (duration > 100) duration = 0;

	right_up = { position.x - platformB->TextureSize().x * 0.5f,
		position.y + platformB->TextureSize().y - 30.0f };
	left_up = { position.x + platformB->TextureSize().x * 0.5f,
		position.y + platformB->TextureSize().y - 30.0f };
	platformB->Position(position);
	propellor->Position(propellor_pos);
	shadow_fx->Position(shadow_pos);
	platformB->Update(V, P);
	propellor->Update(V, P);
	shadow_fx->Update(V, P);
}

void PlatformB::Render()
{
	propellor->Render();
	platformB->Render();
	shadow_fx->Render();
}

void PlatformB::Play()
{
	platformB->Play(0);
	propellor->Play(0);
	shadow_fx->Play(0);
}

Vector2 PlatformB::RightUpPos()
{
	return right_up;
}

Vector2 PlatformB::LeftUpPos()
{
	return left_up;
}
