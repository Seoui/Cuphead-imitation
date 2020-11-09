#include "stdafx.h"
#include "Boomerang.h"

Boomerang::Boomerang(Vector2 _position, Vector2 _scale)
	: EnemyObject(_position, _scale)
	, b_rotate_up(true), b_live(false)
{
	wstring boomerang_texture = L"Bosses/Cagney Carnation/Creating Object/Boomerang/Boomerang.png";
	boomerang_clip = make_unique<Clip>(PlayMode::Loop);
	boomerang_clip->AddFrame(new Sprite(boomerang_texture, shader_file, 0, 0, 166, 121), 0.1f);
	boomerang_clip->AddFrame(new Sprite(boomerang_texture, shader_file, 0, 121, 211, 229), 0.1f);
	boomerang_clip->AddFrame(new Sprite(boomerang_texture, shader_file, 0, 229, 157, 342), 0.1f);
	boomerang_clip->AddFrame(new Sprite(boomerang_texture, shader_file, 0, 342, 169, 431), 0.1f);
	boomerang_clip->AddFrame(new Sprite(boomerang_texture, shader_file, 0, 431, 125, 524), 0.1f);
	boomerang_clip->AddFrame(new Sprite(boomerang_texture, shader_file, 0, 524, 197, 614), 0.1f);
	boomerang_clip->AddFrame(new Sprite(boomerang_texture, shader_file, 0, 614, 156, 711), 0.1f);
	boomerang_clip->AddFrame(new Sprite(boomerang_texture, shader_file, 0, 711, 176, 829), 0.1f);

	shadow_fx = make_unique<Clip>(PlayMode::Loop);
	shadow_fx->AddFrame(new Sprite(boomerang_texture, shader_file, 0, 829, 115, 851), 0.1f);
	shadow_fx->AddFrame(new Sprite(boomerang_texture, shader_file, 0, 851, 123, 872), 0.1f);
	shadow_fx->AddFrame(new Sprite(boomerang_texture, shader_file, 0, 872, 111, 889), 0.1f);

	wstring special_fx = L"Bosses/Cagney Carnation/Creating Object/Special Effects/Special_Effects.png";
	creating_fx = make_unique<Clip>(PlayMode::Once);
	creating_fx->AddFrame(new Sprite(special_fx, shader_file, 0, 0, 106, 93), 0.1f);
	creating_fx->AddFrame(new Sprite(special_fx, shader_file, 0, 93, 175, 384), 0.1f);
	creating_fx->AddFrame(new Sprite(special_fx, shader_file, 0, 384, 170, 788), 0.1f);
	creating_fx->AddFrame(new Sprite(special_fx, shader_file, 0, 788, 172, 1204), 0.1f);
	creating_fx->AddFrame(new Sprite(special_fx, shader_file, 0, 1204, 178, 1630), 0.1f);
	creating_fx->AddFrame(new Sprite(special_fx, shader_file, 0, 1630, 172, 2063), 0.1f);
	creating_fx->AddFrame(new Sprite(special_fx, shader_file, 0, 2063, 167, 2505), 0.1f);
	creating_fx->AddFrame(new Sprite(special_fx, shader_file, 0, 2505, 167, 2952), 0.1f);
	creating_fx->AddFrame(new Sprite(special_fx, shader_file, 0, 2952, 170, 3369), 0.1f);
	creating_fx->AddFrame(new Sprite(special_fx, shader_file, 0, 3369, 158, 3792), 0.1f);
	creating_fx->AddFrame(new Sprite(special_fx, shader_file, 0, 3792, 157, 4220), 0.1f);
	creating_fx->AddFrame(new Sprite(special_fx, shader_file, 0, 4220, 134, 4655), 0.1f);
	creating_fx->AddFrame(new Sprite(special_fx, shader_file, 0, 4655, 133, 5092), 0.1f);
	creating_fx->AddFrame(new Sprite(special_fx, shader_file, 0, 5092, 129, 5533), 0.1f);
	creating_fx->AddFrame(new Sprite(special_fx, shader_file, 0, 5533, 125, 5989), 0.1f);
}

void Boomerang::Update(Matrix & V, Matrix & P)
{
	if (b_rotate_up)
	{
		position.x -= 600 * Time::Delta();
		if (position.x < -1000)
			b_rotate_up = false;
	}
	else
	{
		position.y = -200;
		position.x += 600 * Time::Delta();
		if (position.x > 1000)
		{
			StaticCollisionList::EraseEnemyObject(this);
			Die();
		}
	}
	boomerang_clip->Position(position);
	boomerang_clip->Update(V, P);
	shadow_fx->Position(Vector2(position.x, -250));
	shadow_fx->Update(V, P);
	creating_fx->Position(Vector2(227, 10));
	creating_fx->Update(V, P);
	collider->World(boomerang_clip->World(), Vector2(0.6f, 0.6f));
	collider->Update(V, P);
}

void Boomerang::Render()
{
	boomerang_clip->Render();
	shadow_fx->Render();
	creating_fx->Render();
	//collider->Render();
}

void Boomerang::Play()
{
	boomerang_clip->Play(0);
	shadow_fx->Play(0);
	creating_fx->Play(0);
}

bool Boomerang::IsPlayEnd()
{
	return false;
}

void Boomerang::Spawn(Vector2 _position)
{
	b_live = true;
	position = _position;
	Play();
}

void Boomerang::Die()
{
	b_live = false;
}

bool Boomerang::IsLive()
{
	return b_live;
}