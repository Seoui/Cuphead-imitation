#include "stdafx.h"
#include "MiniFlowerSeed.h"

MiniFlowerSeed::MiniFlowerSeed(Vector2 _position, Vector2 _scale)
	: EnemyObject(_position, _scale), grow_pos(0, 0), b_live(false), b_dead(false)
{
	seed_anim = make_unique<Animation>();
	Clip* clip;
	wstring seed_texture = L"Bosses/Cagney Carnation/Firing Seeds/Mini Flower/Seed/Cagney_mf_seed.png";
	{	// Fall
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 0  , 43, 56), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 56, 42, 112), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 112, 43, 168), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 168, 43, 225), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 225, 44, 283), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 283, 44, 341), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 341, 43, 399), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 399, 44, 458), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 458, 41, 513), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 513, 43, 572), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 572, 43, 631), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 631, 43, 689), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 689, 40, 744), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 744, 40, 799), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 799, 40, 851), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 851, 40, 904), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 904, 41, 958), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 958, 40, 1012), 0.1f);
		seed_anim->AddClip(clip);
	}
	wstring burst_texture = L"Bosses/Cagney Carnation/Firing Seeds/Cagney_groundburst.png";
	{	// Grow
		clip = new Clip(PlayMode::End);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 1012, 51, 1073), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 1073, 53, 1129), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 1129, 54, 1181), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 1181, 49, 1230), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 1230, 51, 1275), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 1275, 57, 1312), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 1312, 61, 1343), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 1343, 64, 1367), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 1367, 14, 1376), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 1376, 13, 1383), 0.1f);
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

void MiniFlowerSeed::Update(Matrix & V, Matrix & P)
{
	if (position.y < -240)
	{
		position.y = -239;
		Play(MINIFLOWER_SEED_STATE::Grow);
	}
	else
		position.y -= 190 * Time::Delta();

	if (IsPlayEnd(MINIFLOWER_SEED_STATE::Grow))
	{
		Die();
		StaticCollisionList::EraseEnemyObject(this);
	}
	seed_anim->Position(position);
	seed_anim->Update(V, P);
	collider->World(seed_anim->World(), Vector2(0.6f, 0.6f));
	collider->Update(V, P);
}

void MiniFlowerSeed::Render()
{
	seed_anim->Render();
}

void MiniFlowerSeed::Play(MINIFLOWER_SEED_STATE state)
{
	seed_anim->Play((UINT)state);
}

bool MiniFlowerSeed::IsPlayEnd(MINIFLOWER_SEED_STATE state)
{
	return seed_anim->IsPlayEnd((UINT)state);
}

void MiniFlowerSeed::Spawn(Vector2 _position)
{
	b_live = true;
	b_dead = false;
	position = _position;
	Play(MINIFLOWER_SEED_STATE::Fall);
}

void MiniFlowerSeed::Die()
{
	b_live = false;
	b_dead = true;
	grow_pos = position;
	position = Vector2(500, 500);
}

void MiniFlowerSeed::Wait()
{
	b_live = false;
	b_dead = false;
}

bool MiniFlowerSeed::IsLive()
{
	return b_live;
}

bool MiniFlowerSeed::IsDead()
{
	return b_dead;
}

Vector2 & MiniFlowerSeed::GrowPosition()
{
	return grow_pos;
}
