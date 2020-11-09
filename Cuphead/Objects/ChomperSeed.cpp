#include "stdafx.h"
#include "ChomperSeed.h"

ChomperSeed::ChomperSeed(Vector2 _position, Vector2 _scale)
	: EnemyObject(_position, _scale)
	, grow_pos(0, 0), b_live(false), b_dead(false)
{
	seed_anim = make_unique<Animation>();
	Clip* clip;
	wstring seed_texture = L"Bosses/Cagney Carnation/Firing Seeds/Chomper/Seed/Cagney_chomper_seed.png";
	{	// Fall
		clip = new Clip(PlayMode::RoundLoop);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 0, 43, 55), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 55, 42, 111), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 111, 43, 167), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 167, 43, 224), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 224, 44, 282), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 282, 44, 341), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 341, 43, 399), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 399, 44, 458), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 458, 41, 513), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 513, 43, 572), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 572, 43, 631), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 631, 40, 686), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 686, 43, 744), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 744, 40, 799), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 799, 41, 853), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 853, 41, 907), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 907, 40, 959), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 959, 40, 1012), 0.1f);
		seed_anim->AddClip(clip);
	}
	wstring burst_texture = L"Bosses/Cagney Carnation/Firing Seeds/Cagney_groundburst.png";
	{	// Grow
		clip = new Clip(PlayMode::End);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 1012, 50, 1073), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 1073, 52, 1130), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 1130, 52, 1183), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 1183, 48, 1233), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 1233, 49, 1279), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 1279, 55, 1317), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 1317, 59, 1349), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 1349, 62, 1374), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 1374, 12, 1384), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 1384, 11, 1392), 0.1f);
		clip->AddFrame(new Sprite(burst_texture, shader_file, 44, 392, 121, 422), 0.1f);
		clip->AddFrame(new Sprite(burst_texture, shader_file, 43, 804, 121, 844), 0.1f);
		clip->AddFrame(new Sprite(burst_texture, shader_file, 43, 1218, 121, 1266), 0.1f);
		clip->AddFrame(new Sprite(burst_texture, shader_file, 43, 1218, 121, 1266), 0.1f);
		clip->AddFrame(new Sprite(burst_texture, shader_file, 43, 804, 121, 844), 0.1f);
		clip->AddFrame(new Sprite(burst_texture, shader_file, 44, 392, 121, 422), 0.1f);
		clip->AddFrame(new Sprite(burst_texture, shader_file, 44, 392, 121, 422), 0.1f);
		clip->AddFrame(new Sprite(burst_texture, shader_file, 43, 804, 121, 844), 0.1f);
		clip->AddFrame(new Sprite(burst_texture, shader_file, 43, 1218, 121, 1266), 0.1f);
		clip->AddFrame(new Sprite(burst_texture, shader_file, 43, 1218, 121, 1266), 0.1f);
		clip->AddFrame(new Sprite(burst_texture, shader_file, 43, 804, 121, 844), 0.1f);
		clip->AddFrame(new Sprite(burst_texture, shader_file, 44, 392, 121, 422), 0.1f);
		clip->AddFrame(new Sprite(burst_texture, shader_file, 44, 392, 121, 422), 0.1f);
		clip->AddFrame(new Sprite(burst_texture, shader_file, 43, 804, 121, 844), 0.1f);
		clip->AddFrame(new Sprite(burst_texture, shader_file, 43, 1218, 121, 1266), 0.1f);
		clip->AddFrame(new Sprite(burst_texture, shader_file, 47, 1633, 119, 1670), 0.1f);
		clip->AddFrame(new Sprite(burst_texture, shader_file, 38, 2041, 131, 2082), 0.1f);
		clip->AddFrame(new Sprite(burst_texture, shader_file, 26, 2448, 140, 2493), 0.1f);
		clip->AddFrame(new Sprite(burst_texture, shader_file, 22, 2881, 151, 2912), 0.1f);
		seed_anim->AddClip(clip);
	}
}

void ChomperSeed::Update(Matrix & V, Matrix & P)
{
	if (position.y < -240)
	{
		position.y = -239;
		Play(CHOMPER_SEED_STATE::Grow);
	}
	else
		position.y -= 200 * Time::Delta();

	if (IsPlayEnd(CHOMPER_SEED_STATE::Grow))
	{
		Die();
		StaticCollisionList::EraseEnemyObject(this);
	}
	seed_anim->Position(position);
	seed_anim->Update(V, P);
	collider->World(seed_anim->World(), Vector2(0.6f, 0.6f));
	collider->Update(V, P);
}

void ChomperSeed::Render()
{
	seed_anim->Render();
}                              

void ChomperSeed::Play(CHOMPER_SEED_STATE state)
{
	seed_anim->Play((UINT)state);
}

bool ChomperSeed::IsPlayEnd(CHOMPER_SEED_STATE state)
{
	return seed_anim->IsPlayEnd((UINT)state);
}

void ChomperSeed::Spawn(Vector2 _position)
{
	b_live = true;
	b_dead = false;
	position = _position;
	Play(CHOMPER_SEED_STATE::Fall);
}

void ChomperSeed::Die()
{
	b_dead = true;
	b_live = false;
	grow_pos = position;
	position = Vector2(500, 500);
}

void ChomperSeed::Wait()
{
	b_live = false;
	b_dead = false;
}

bool ChomperSeed::IsLive()
{
	return b_live;
}

bool ChomperSeed::IsDead()
{
	return b_dead;
}

Vector2 & ChomperSeed::GrowPosition()
{
	return grow_pos;
}