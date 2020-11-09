#include "stdafx.h"
#include "VenusVine.h"

VenusVine::VenusVine(Vector2 _position, Vector2 _scale)
	: EnemyObject(_position, _scale),
	  b_live(false), b_dead(false), b_grow(false)
{
	wstring vine_texture = L"Bosses/Cagney Carnation/Firing Seeds/Venus Flytrap/Vine/Venus_Vine.png";
	vine_clip = make_unique<Clip>(PlayMode::End);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 0, 63, 46), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 46, 45, 111), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 111, 51, 202), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 202, 57, 337), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 337, 57, 490), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 490, 50, 675), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 675, 57, 885), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 885, 66, 1122), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 1122, 66, 1367), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 1367, 68, 1629), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 1629, 65, 1887), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 1887, 67, 2154), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 2154, 75, 2413), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 2413, 73, 2672), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 2672, 70, 2930), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 2930, 69, 3186), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 3186, 69, 3443), 0.1f);

	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 3443, 71, 3700), 0.1f);

	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 3186, 69, 3443), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 2930, 69, 3186), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 2672, 70, 2930), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 2413, 73, 2672), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 2154, 75, 2413), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 1887, 67, 2154), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 1629, 65, 1887), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 1367, 68, 1629), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 1122, 66, 1367), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 885, 66, 1122), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 675, 57, 885), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 490, 50, 675), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 337, 57, 490), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 202, 57, 337), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 111, 51, 202), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 46, 45, 111), 0.1f);
	vine_clip->AddFrame(new Sprite(vine_texture, shader_file, 0, 0, 63, 46), 0.1f);
}

void VenusVine::Update(Matrix & V, Matrix & P)
{
	if (vine_clip->CurrentFrame() == 17)
	{
		b_grow = true;
	}
	else if (vine_clip->CurrentFrame() == 18)
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

void VenusVine::Render()
{
	vine_clip->Render();
}

void VenusVine::Play()
{
	vine_clip->Play(0);
}

bool VenusVine::IsPlayEnd()
{
	return vine_clip->IsPlayEnd();
}

void VenusVine::Spawn(Vector2 _position)
{
	b_live = true;
	b_dead = false;
	b_grow = false;
	position = _position;
	Play();
}

void VenusVine::Die()
{
	b_live = false;
	b_dead = true;
	position = Vector2(500, 500);
}

void VenusVine::Wait()
{
	b_live = false;
	b_dead = false;
}

bool VenusVine::IsLive()
{
	return b_live;
}

bool VenusVine::IsDead()
{
	return b_dead;
}

bool VenusVine::IsGrow()
{
	return b_grow;
}
