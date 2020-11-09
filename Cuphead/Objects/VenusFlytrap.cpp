#include "stdafx.h"
#include "VenusFlytrap.h"
#include "Character/Bosses/Cagney.h"

VenusFlytrap::VenusFlytrap(Vector2 _position, Vector2 _scale)
	: Attackable(_position, _scale), b_live(false), cuphead_pos(0, 0)
{
	health = 15.0f;
	flytrap_anim = make_unique<Animation>();
	Clip* clip;
	wstring flytrap_texture = L"Bosses/Cagney Carnation/Firing Seeds/Venus Flytrap/Cagney_venus.png";
	{	// Move
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(flytrap_texture, shader_file, 0, 0, 36, 29), 0.1f);
		clip->AddFrame(new Sprite(flytrap_texture, shader_file, 0, 29, 41, 68), 0.1f);
		clip->AddFrame(new Sprite(flytrap_texture, shader_file, 0, 68, 45, 109), 0.1f);
		clip->AddFrame(new Sprite(flytrap_texture, shader_file, 0, 109, 52, 158), 0.1f);
		clip->AddFrame(new Sprite(flytrap_texture, shader_file, 0, 158, 54, 209), 0.1f);
		clip->AddFrame(new Sprite(flytrap_texture, shader_file, 0, 209, 56, 267), 0.1f);
		clip->AddFrame(new Sprite(flytrap_texture, shader_file, 0, 267, 60, 331), 0.1f);
		clip->AddFrame(new Sprite(flytrap_texture, shader_file, 0, 331, 66, 394), 0.1f);
		clip->AddFrame(new Sprite(flytrap_texture, shader_file, 0, 394, 81, 460), 0.1f);
		clip->AddFrame(new Sprite(flytrap_texture, shader_file, 0, 460, 115, 513), 0.1f);
		clip->AddFrame(new Sprite(flytrap_texture, shader_file, 0, 513, 81, 571), 0.1f);
		clip->AddFrame(new Sprite(flytrap_texture, shader_file, 0, 571, 74, 633), 0.1f);
		flytrap_anim->AddClip(clip);
	}
	{	//HX Attack 구현 못함.. 텍스처 파일의 B 부분임
		clip = new Clip(PlayMode::End);
		clip->AddFrame(new Sprite(flytrap_texture, shader_file, 0, 0, 69, 67), 0.1f);
		clip->AddFrame(new Sprite(flytrap_texture, shader_file, 0, 67, 79, 147), 0.1f);
		clip->AddFrame(new Sprite(flytrap_texture, shader_file, 0, 147, 124, 290), 0.1f);
		clip->AddFrame(new Sprite(flytrap_texture, shader_file, 0, 290, 206, 522), 0.1f);
		clip->AddFrame(new Sprite(flytrap_texture, shader_file, 0, 522, 218, 789), 0.1f);
		clip->AddFrame(new Sprite(flytrap_texture, shader_file, 0, 789, 249, 1078), 0.1f);
		clip->AddFrame(new Sprite(flytrap_texture, shader_file, 0, 1078, 276, 1376), 0.1f);
		clip->AddFrame(new Sprite(flytrap_texture, shader_file, 0, 1376, 271, 1631), 0.1f);
		clip->AddFrame(new Sprite(flytrap_texture, shader_file, 0, 1631, 292, 1899), 0.1f);
		clip->AddFrame(new Sprite(flytrap_texture, shader_file, 0, 1899, 233, 2181), 0.1f);
		flytrap_anim->AddClip(clip);
	}
	wstring dead_texture = L"Bosses/Cagney Carnation/Firing Seeds/Venus Flytrap/Death/Venus_Die.png";
	{	// Dead
		clip = new Clip(PlayMode::End);
		clip->AddFrame(new Sprite(dead_texture, shader_file, 0, 0, 69, 67), 0.1f);
		clip->AddFrame(new Sprite(dead_texture, shader_file, 0, 67, 79, 147), 0.1f);
		clip->AddFrame(new Sprite(dead_texture, shader_file, 0, 147, 124, 290), 0.1f);
		clip->AddFrame(new Sprite(dead_texture, shader_file, 0, 290, 206, 522), 0.1f);
		clip->AddFrame(new Sprite(dead_texture, shader_file, 0, 522, 218, 789), 0.1f);
		clip->AddFrame(new Sprite(dead_texture, shader_file, 0, 789, 249, 1078), 0.1f);
		clip->AddFrame(new Sprite(dead_texture, shader_file, 0, 1078, 276, 1376), 0.1f);
		clip->AddFrame(new Sprite(dead_texture, shader_file, 0, 1376, 271, 1631), 0.1f);
		clip->AddFrame(new Sprite(dead_texture, shader_file, 0, 1631, 292, 1899), 0.1f);
		clip->AddFrame(new Sprite(dead_texture, shader_file, 0, 1899, 233, 2181), 0.1f);
		flytrap_anim->AddClip(clip);
	}
}

void VenusFlytrap::Update(Matrix & V, Matrix & P)
{
	if (health < 0)
	{
		Die();
		collider->Position(Vector2(500, 500));
		if (IsPlayEnd(FLYTRAP_STATE::Dead))
		{
			position = Vector2(500, 500);
			b_live = false;
		}
		StaticCollisionList::EraseAttackable(this);
	}
	else
	{
		// flytrap에서 cuphead로 향하는 방향벡터
		Vector2 target_dir = Vector2(cuphead_pos.x, cuphead_pos.y - 30) - position;
		rotation.y = (target_dir.x > 0) ? Math::PI : 0;
		D3DXVec2Normalize(&target_dir, &target_dir);
		position += target_dir * 80 * Time::Delta();
		/* HX 나중에
		// flytrap의 x축 방향벡터
		Vector2 direction = { flytrap_anim->ForwardVector(), 0 };
		// 두 벡터의 곱
		d_time = Time::Delta();
		if (d_time > acctime) {
			float length1 = D3DXVec2Length(&target_dir);
			float cross = (target_dir.x * direction.y) - (target_dir.y * direction.x);
			rotation.z = acosf(target_dir.x / length1);
			if (cross > 0)
				rotation.z *= -1;
		}
		*/
	}
	flytrap_anim->Rotation(rotation);
	flytrap_anim->Position(position);
	flytrap_anim->Update(V, P);
	collider->World(flytrap_anim->World(), Vector2(0.6f, 1.0f));
	collider->Update(V, P);
}

void VenusFlytrap::Render()
{
	flytrap_anim->Render();
}

void VenusFlytrap::CupheadPosition(Vector2 _position)
{
	cuphead_pos = _position;
}

void VenusFlytrap::Play(FLYTRAP_STATE state)
{
	flytrap_anim->Play((UINT)state);
}

bool VenusFlytrap::IsPlayEnd(FLYTRAP_STATE state)
{
	return flytrap_anim->IsPlayEnd((UINT)state);
}

void VenusFlytrap::Spawn(Vector2 _position)
{
	b_live = true;
	position = { _position.x, _position.y + 200 };
	Play(FLYTRAP_STATE::Normal);
}

void VenusFlytrap::Die()
{
	Play(FLYTRAP_STATE::Dead);
}

bool VenusFlytrap::IsLive()
{
	return b_live;
}