#include "stdafx.h"
#include "MiniFlower.h"

//HX MiniFlower Attack 구현 아직 안함
// 따로 clip으로 구현하든지 해야 할 듯
MiniFlower::MiniFlower(Vector2 _position, Vector2 _scale)
	: Attackable(_position, _scale), b_live(false), d_time(0)
{
	health = 15.0f;
	flower_anim = make_unique<Animation>();
	Clip* clip;
	wstring flower_texture = L"Bosses/Cagney Carnation/Firing Seeds/Mini Flower/Cagney_mf.png";
	{	// MiniFlower
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 0, 34, 26), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 26, 58, 59), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 59, 78, 106), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 106, 97, 165), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 165, 103, 227), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 227, 104, 293), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 293, 114, 356), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 356, 118, 424), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 424, 111, 488), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 488, 112, 548), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 548, 109, 614), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 614, 101, 691), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 691, 96, 767), 0.1f);
		flower_anim->AddClip(clip);
	}
	{	// Fire
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 767, 102, 853), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 853, 125, 947), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 947, 144, 1053), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 1053, 166, 1176), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 1176, 161, 1297), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 1297, 163, 1421), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 1421, 158, 1546), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 1546, 159, 1670), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 1670, 156, 1796), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 1796, 161, 1923), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 1923, 162, 2049), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 2049, 153, 2176), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 2176, 148, 2306), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 2306, 137, 2437), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 2437, 152, 2566), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 2566, 160, 2698), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 2698, 149, 2828), 0.1f);
		flower_anim->AddClip(clip);
	}
	{	// Dead
		clip = new Clip(PlayMode::End);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 3430, 182, 3567), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 3567, 193, 3738), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 3738, 130, 3867), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 3867, 241, 4139), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 4139, 292, 4456), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 4456, 337, 4822), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 4822, 373, 5215), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 5215, 384, 5611), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 5611, 416, 6042), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 6042, 186, 6239), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 6239, 168, 6432), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 6432, 152, 6616), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 6616, 150, 6776), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 6776, 148, 6909), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 6909, 130, 7043), 0.1f);
		clip->AddFrame(new Sprite(flower_texture, shader_file, 0, 7043, 121, 7154), 0.1f);
		flower_anim->AddClip(clip);
	}
}

void MiniFlower::Update(Matrix & V, Matrix & P)
{
	if (d_time > 100) d_time = 0;
	if (health < 0)
	{
		Die();
		collider->Position(Vector2(500, 500));
		if (IsPlayEnd(MINIFLOWER_STATE::Dead))
		{
			position = Vector2(500, 500);
			b_live = false;
			StaticCollisionList::EraseAttackable(this);
		}
	}
	else 
	{
		d_time += Time::Delta();
		if (position.y > 240)
			position.x += 0.05f * sin(2 * d_time);
		else
			position.y += 150 * Time::Delta();
	}
	flower_anim->Position(position);
	flower_anim->Update(V, P);
	collider->World(flower_anim->World(), Vector2(0.8f, 0.8f));
	collider->Update(V, P);
}

void MiniFlower::Render()
{
	flower_anim->Render();
	//collider->Render();
}

void MiniFlower::Play(MINIFLOWER_STATE state)
{
	if (state == MINIFLOWER_STATE::Normal)
		flower_anim->Play((UINT)state, 4);
	else
		flower_anim->Play((UINT)state);
}

bool MiniFlower::IsPlayEnd(MINIFLOWER_STATE state)
{
	return flower_anim->IsPlayEnd((UINT)state);
}

void MiniFlower::Spawn(Vector2 _position)
{
	b_live = true;
	position = { _position.x, _position.y + 200 };
	Play(MINIFLOWER_STATE::Normal);
}

void MiniFlower::Die()
{
	Play(MINIFLOWER_STATE::Dead);
}

bool MiniFlower::IsLive()
{
	return b_live;
}