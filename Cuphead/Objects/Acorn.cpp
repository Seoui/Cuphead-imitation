#include "stdafx.h"
#include "Acorn.h"
#include "Character/Bosses/Cagney.h"

Acorn::Acorn(Vector2 _position, Vector2 _scale)
	: EnemyObject(_position, _scale), spawn_pos(0, 0), cuphead_pos(0, 0)
	, b_live(false), b_rush(false)
	, d_time(0), rotate_time(0), slope(0)
{
	acorn_anim = make_unique<Animation>();
	Clip* clip;
	wstring acorn_texture = L"Bosses/Cagney Carnation/Creating Object/Acorn/Acorn.png";
	{	// rotate
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(acorn_texture, shader_file, 0, 0, 68, 60), 0.1f);
		clip->AddFrame(new Sprite(acorn_texture, shader_file, 0, 60, 62, 118), 0.1f);
		clip->AddFrame(new Sprite(acorn_texture, shader_file, 0, 118, 62, 181), 0.1f);
		clip->AddFrame(new Sprite(acorn_texture, shader_file, 0, 181, 60, 240), 0.1f);
		clip->AddFrame(new Sprite(acorn_texture, shader_file, 0, 240, 67, 299), 0.1f);
		clip->AddFrame(new Sprite(acorn_texture, shader_file, 0, 299, 62, 363), 0.1f);
		clip->AddFrame(new Sprite(acorn_texture, shader_file, 0, 363, 60, 430), 0.1f);
		clip->AddFrame(new Sprite(acorn_texture, shader_file, 0, 430, 60, 491), 0.1f);
		acorn_anim->AddClip(clip);
	}
	{	// rush
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(acorn_texture, shader_file, 0, 491, 88, 529), 0.1f);
		clip->AddFrame(new Sprite(acorn_texture, shader_file, 0, 529, 85, 567), 0.1f);
		clip->AddFrame(new Sprite(acorn_texture, shader_file, 0, 567, 88, 603), 0.1f);
		clip->AddFrame(new Sprite(acorn_texture, shader_file, 0, 603, 88, 640), 0.1f);
		acorn_anim->AddClip(clip);
	}
}

void Acorn::Update(Matrix & V, Matrix & P)
{
	if (d_time > rotate_time && b_rush == false)
	{
		// cuphead_pos는 매프레임 씬에서 동기화된다.
		slope = (cuphead_pos.y - spawn_pos.y) / (cuphead_pos.x - spawn_pos.x);
		b_rush = true;	
	}
	else if(d_time < rotate_time)
	{
		d_time += Time::Delta();
	}
	if (b_rush)
	{
		// 시계 반대반향으로 회전한다.
		rotation.z = atanf(slope);
		position.x -= 600 * Time::Delta();
		position.y -= slope * 600 * Time::Delta();
		Play(ACORN_STATE::Rush);
		if (position.x < -1000)
		{
			Die();
			b_rush = false;
			StaticCollisionList::EraseEnemyObject(this);
		}
	}
	acorn_anim->Rotation(rotation);
	acorn_anim->Position(position);
	acorn_anim->Update(V, P);
	collider->World(acorn_anim->World(), Vector2(0.6f, 0.6f));
	collider->Update(V, P);
}

void Acorn::Render()
{
	acorn_anim->Render();
	//collider->Render();
}

void Acorn::Play(ACORN_STATE state)
{
	acorn_anim->Play((UINT)state);
}

bool Acorn::IsPlayEnd(ACORN_STATE state)
{
	return acorn_anim->IsPlayEnd((UINT)state);
}

void Acorn::Spawn(Vector2 _position, float _rotate_time)
{
	b_live = true;
	position = _position;
	spawn_pos = _position;
	rotate_time = _rotate_time;
	Play(ACORN_STATE::Rotate);
}

void Acorn::Die()
{
	b_live = false;
}

bool Acorn::IsLive()
{
	return b_live;
}

void Acorn::CupheadPosition(Vector2 _position)
{
	cuphead_pos = _position;
}