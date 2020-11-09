#include "stdafx.h"
#include "VenusSeed.h"

VenusSeed::VenusSeed(Vector2 _position, Vector2 _scale)
	: EnemyObject(_position, _scale), b_live(false), b_dead(false)
{
	seed_anim = make_unique<Animation>();
	Clip* clip;
	wstring seed_texture = L"Bosses/Cagney Carnation/Firing Seeds/Venus Flytrap/Seed/Cagney_venus_seed.png";
	{	// Fall
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 0, 43, 55), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 55, 42, 111), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 111, 43, 167), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 167, 43, 224), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 224, 44, 282), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 282, 44, 340), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 340, 43, 398), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 398, 44, 457), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 457, 43, 516), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 516, 43, 575), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 575, 43, 633), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 633, 40, 688), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 688, 40, 742), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 742, 40, 795), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 795, 40, 847), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 847, 42, 901), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 901, 40, 956), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 956, 41, 1011), 0.1f);
		seed_anim->AddClip(clip);
	}
	wstring burst_texture = L"Bosses/Cagney Carnation/Firing Seeds/Cagney_groundburst.png";
	{	// Grow
		clip = new Clip(PlayMode::End);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 1011, 49, 1072), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 1072, 52, 1128), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 1128, 52, 1180), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 1180, 48, 1229), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 1229, 50, 1273), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 1273, 56, 1310), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 1310, 60, 1341), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 1341, 63, 1365), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 1365, 13, 1374), 0.1f);
		clip->AddFrame(new Sprite(seed_texture, shader_file, 0, 1374, 12, 1381), 0.1f);
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

void VenusSeed::Update(Matrix & V, Matrix & P)
{
	if (position.y < -240)
	{
		position.y = -239;
		Play(VENUS_SEED_STATE::Grow);
		collider->Position(Vector2(500, 500));
	}
	else
		position.y -= 200 * Time::Delta();

	if (IsPlayEnd(VENUS_SEED_STATE::Grow))
	{
		Die();
		StaticCollisionList::EraseEnemyObject(this);
	}
	seed_anim->Position(position);
	seed_anim->Update(V, P);
	collider->World(seed_anim->World(), Vector2(0.6f, 0.6f));
	collider->Update(V, P);
}

void VenusSeed::Render()
{
	seed_anim->Render();
}

void VenusSeed::Play(VENUS_SEED_STATE state)
{
	seed_anim->Play((UINT)state);
}

bool VenusSeed::IsPlayEnd(VENUS_SEED_STATE state)
{
	return seed_anim->IsPlayEnd((UINT)state);
}

void VenusSeed::Spawn(Vector2 _position)
{
	b_live = true;
	b_dead = false;
	position = _position;
	Play(VENUS_SEED_STATE::Fall);
}

void VenusSeed::Die()
{
	b_live = false;
	b_dead = true;
	grow_pos = position;
	position = Vector2(500, 500);
}

void VenusSeed::Wait()
{
	b_live = false;
	b_dead = false;
}

bool VenusSeed::IsLive()
{
	return b_live;
}

bool VenusSeed::IsDead()
{
	return b_dead;
}

Vector2 & VenusSeed::GrowPosition()
{
	return grow_pos;
}