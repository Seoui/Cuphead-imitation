#include "stdafx.h"
#include "PlatformA.h"

PlatformA::PlatformA(Vector2 _position, Vector2 _scale)
	: Platform(_position, _scale)
	, right_up(0, 0), left_up(0, 0)
{
	platformA = make_unique<Clip>(PlayMode::Loop);
	platformA->AddFrame(new Sprite(platform_texture, shader_file, 0, 0, 158, 90), 0.1f);
	platformA->AddFrame(new Sprite(platform_texture, shader_file, 0, 90, 159, 179), 0.1f);
	platformA->AddFrame(new Sprite(platform_texture, shader_file, 0, 179, 160, 268), 0.1f);
	platformA->Position(_position);
	platformA->Scale(_scale);

	propellor_pos = Vector2(_position.x + 5, _position.y - 18);
	propellor->Position(propellor_pos);

	shadow_pos = Vector2(_position.x + 5, _position.y - 120);
	shadow_fx->Position(shadow_pos);

	Play();
}

void PlatformA::Update(Matrix & V, Matrix & P)
{
	duration += Time::Delta();
	position.y += 0.005f * sin(2 * duration);
	propellor_pos.y += 0.005f * sin(2 * duration);
	if (duration > 100) duration = 0;

	right_up = { position.x - platformA->TextureSize().x * 0.5f,
		position.y + platformA->TextureSize().y - 30.0f };
	left_up = { position.x + platformA->TextureSize().x * 0.5f,
		position.y + platformA->TextureSize().y - 30.0f };
	platformA->Position(position);
	propellor->Position(propellor_pos);
	shadow_fx->Position(shadow_pos);
	propellor->Update(V, P);
	platformA->Update(V, P);
	shadow_fx->Update(V, P);
}

void PlatformA::Render()
{
	propellor->Render();
	platformA->Render();
	shadow_fx->Render();
}

void PlatformA::Play()
{
	platformA->Play(0);
	propellor->Play(0);
	shadow_fx->Play(0);
}

Vector2 PlatformA::RightUpPos()
{
	return right_up;
}

Vector2 PlatformA::LeftUpPos()
{
	return left_up;
}
