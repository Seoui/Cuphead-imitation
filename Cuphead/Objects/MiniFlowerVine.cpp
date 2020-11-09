#include "stdafx.h"
#include "MiniFlowerVine.h"

MiniFlowerVine::MiniFlowerVine(Vector2 _position, Vector2 _scale)
	: EnemyObject(_position, _scale),
	  b_live(false), b_dead(false), b_grow(false)
{
	wstring vine_texture = L"Bosses/Cagney Carnation/Firing Seeds/Mini Flower/Vine/MF_Vine.png";
	vine_clip = make_unique<Clip>(PlayMode::End);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 0, 49, 76), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 76, 49, 175), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 175, 58, 301), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 301, 58, 463), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 463, 51, 659), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 659, 57, 904), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 904, 61, 1189), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 1189, 61, 1492), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 1492, 60, 1810), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 1810, 60, 2138), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 2138, 72, 2470), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 2470, 72, 2798), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 2798, 69, 3124), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 3124, 70, 3446), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 3446, 78, 3768), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 3768, 84, 4089), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 4089, 83, 4413), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 3768, 84, 4089), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 3446, 78, 3768), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 3124, 70, 3446), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 2798, 69, 3124), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 2470, 72, 2798), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 2138, 72, 2470), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 1810, 60, 2138), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 1492, 60, 1810), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 1189, 61, 1492), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 904, 61, 1189), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 659, 57, 904), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 463, 51, 659), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 301, 58, 463), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 175, 58, 301), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 76, 49, 175), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 0, 49, 76), 0.1f);
}

void MiniFlowerVine::Update(Matrix & V, Matrix & P)
{
	if (vine_clip->CurrentFrame() == 16)
	{
		b_grow = true;
	}
	else if (vine_clip->CurrentFrame() == 17)
	{
		b_grow = false;
	}
	if (vine_clip->IsPlayEnd())
	{
		Die();
	}
	vine_clip->Position(position);
	vine_clip->Update(V, P);
}

void MiniFlowerVine::Render()
{
	vine_clip->Render();
}

void MiniFlowerVine::Play()
{
	vine_clip->Play(0);
}

bool MiniFlowerVine::IsPlayEnd()
{
	return vine_clip->IsPlayEnd();
}

void MiniFlowerVine::Spawn(Vector2 _position)
{
	b_live = true;
	b_dead = false;
	b_grow = false;
	position = _position;
	Play();
}

void MiniFlowerVine::Die()
{
	b_live = false;
	b_dead = true;
	position = Vector2(500, 500);
}

void MiniFlowerVine::Wait()
{
	b_live = false;
	b_dead = false;
}

bool MiniFlowerVine::IsLive()
{
	return b_live;
}

bool MiniFlowerVine::IsDead()
{
	return b_dead;
}

bool MiniFlowerVine::IsGrow()
{
	return b_grow;
}