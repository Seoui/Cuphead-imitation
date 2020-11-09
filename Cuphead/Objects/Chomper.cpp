#include "stdafx.h"
#include "Chomper.h"

Chomper::Chomper(Vector2 _position, Vector2 _scale)
	: Attackable(_position, _scale), b_live(false)
{
	health = 15.0f;
	chomper_anim = make_unique<Animation>(_position, _scale);
	Clip* clip;
	wstring chomper_texture = L"Bosses/Cagney Carnation/Firing Seeds/Chomper/Chomper.png";
	{
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(chomper_texture, shader_file, 0, 0, 72, 67), 0.1f);
		clip->AddFrame(new Sprite(chomper_texture, shader_file, 0, 67, 46, 191), 0.1f);
		clip->AddFrame(new Sprite(chomper_texture, shader_file, 0, 191, 45, 294), 0.1f);
		clip->AddFrame(new Sprite(chomper_texture, shader_file, 0, 294, 51, 396), 0.1f);
		clip->AddFrame(new Sprite(chomper_texture, shader_file, 0, 396, 58, 494), 0.1f);
		clip->AddFrame(new Sprite(chomper_texture, shader_file, 0, 494, 57, 576), 0.1f);
		clip->AddFrame(new Sprite(chomper_texture, shader_file, 0, 576, 73, 634), 0.1f);
		clip->AddFrame(new Sprite(chomper_texture, shader_file, 0, 634, 69, 698), 0.1f);
		clip->AddFrame(new Sprite(chomper_texture, shader_file, 0, 698, 61, 763), 0.1f);
		chomper_anim->AddClip(clip);
	}
	wstring dead_texture = L"Bosses/Cagney Carnation/Firing Seeds/Chomper/Death/Chomper_Die.png";
	{
		clip = new Clip(PlayMode::End);
		clip->AddFrame(new Sprite(dead_texture, shader_file, 0, 0, 73, 85), 0.1f);
		clip->AddFrame(new Sprite(dead_texture, shader_file, 0, 85, 66, 167), 0.1f);
		clip->AddFrame(new Sprite(dead_texture, shader_file, 0, 167, 119, 284), 0.1f);
		clip->AddFrame(new Sprite(dead_texture, shader_file, 0, 284, 220, 481), 0.1f);
		clip->AddFrame(new Sprite(dead_texture, shader_file, 0, 481, 217, 681), 0.1f);
		clip->AddFrame(new Sprite(dead_texture, shader_file, 0, 681, 172, 877), 0.1f);
		clip->AddFrame(new Sprite(dead_texture, shader_file, 0, 877, 190, 1075), 0.1f);
		clip->AddFrame(new Sprite(dead_texture, shader_file, 0, 1075, 215, 1301), 0.1f);
		clip->AddFrame(new Sprite(dead_texture, shader_file, 0, 1301, 226, 1537), 0.1f);
		clip->AddFrame(new Sprite(dead_texture, shader_file, 0, 1537, 243, 1795), 0.1f);
		clip->AddFrame(new Sprite(dead_texture, shader_file, 0, 1795, 253, 2056), 0.1f);
		clip->AddFrame(new Sprite(dead_texture, shader_file, 0, 2056, 272, 2329), 0.1f);
		clip->AddFrame(new Sprite(dead_texture, shader_file, 0, 2329, 272, 2602), 0.1f);
		clip->AddFrame(new Sprite(dead_texture, shader_file, 0, 2602, 278, 2884), 0.1f);
		clip->AddFrame(new Sprite(dead_texture, shader_file, 0, 2884, 281, 3164), 0.1f);
		chomper_anim->AddClip(clip);
	}
}

void Chomper::Update(Matrix & V, Matrix & P)
{
	if (health < 0)
	{
		Die();
		collider->Position(Vector2(500, 500));
		if (IsPlayEnd(CHOMPER_STATE::Dead))
		{
			position = Vector2(500, 500);
			b_live = false;
		}
		StaticCollisionList::EraseAttackable(this);
	}
	else
	{
		collider->World(chomper_anim->World(), Vector2(0.6f, 0.6f));
	}
	chomper_anim->Position(position);
	chomper_anim->Update(V, P);
	collider->Update(V, P);
}

void Chomper::Render()
{
	chomper_anim->Render();
}

void Chomper::Play(CHOMPER_STATE state)
{
	chomper_anim->Play((UINT)state);
}

bool Chomper::IsPlayEnd(CHOMPER_STATE state)
{
	return chomper_anim->IsPlayEnd((UINT)state);
}

void Chomper::Spawn(Vector2 _position)
{
	b_live = true;
	position = _position;
	Play(CHOMPER_STATE::Normal);
}

void Chomper::Die()
{
	Play(CHOMPER_STATE::Dead);
}

bool Chomper::IsLive()
{
	return b_live;
}
