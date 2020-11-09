#include "stdafx.h"
#include "Pollen.h"

Pollen::Pollen(Vector2 _position, Vector2 _scale)
	: EnemyObject(_position, _scale)
	, b_live(false), cuphead_pos(0, 0)
{
	wstring pollen_texture = L"Bosses/Cagney Carnation/Final Form/Firing Pollen/Pollen/FP_Pollen.png";
	pollen_pink = make_unique<Clip>(PlayMode::Loop);
	pollen_pink->AddFrame(new Sprite(pollen_texture, shader_file, 0, 0, 56, 55), 0.1f);
	pollen_pink->AddFrame(new Sprite(pollen_texture, shader_file, 0, 55, 54, 108), 0.1f);
	pollen_pink->AddFrame(new Sprite(pollen_texture, shader_file, 0, 108, 52, 162), 0.1f);
	pollen_pink->AddFrame(new Sprite(pollen_texture, shader_file, 0, 162, 49, 212), 0.1f);
	pollen_pink->AddFrame(new Sprite(pollen_texture, shader_file, 0, 212, 49,  260), 0.1f);

	pollen_white = make_unique<Clip>(PlayMode::Loop);
	pollen_white->AddFrame(new Sprite(pollen_texture, shader_file, 0, 260, 57, 316), 0.1f);
	pollen_white->AddFrame(new Sprite(pollen_texture, shader_file, 0, 316, 52, 370), 0.1f);
	pollen_white->AddFrame(new Sprite(pollen_texture, shader_file, 0, 370, 51, 423), 0.1f);
	pollen_white->AddFrame(new Sprite(pollen_texture, shader_file, 0, 423, 49, 474), 0.1f);
	pollen_white->AddFrame(new Sprite(pollen_texture, shader_file, 0, 474, 48, 523), 0.1f);
}

// 랜덤으로 둘중의 하나 pollen 선택해서 업데이트 렌더 해야함.
// 생성될 때 그때의 pollen을 선택하도록 해야함.
void Pollen::Update(Matrix & V, Matrix & P)
{
	duration = Time::Delta();
	if (b_rand)
	{
		position.x -= 500 * Time::Delta();
		position.y -= 0.001f * sin(1000*duration);
		if (position.x < -1000)
		{
			Die();
		}
		pollen_white->Position(position);
		pollen_white->Update(V, P);
		collider->World(pollen_white->World(), Vector2(0.6f, 0.6f));
	}
	else
	{
		position.x -= 500 * Time::Delta();
		position.y -= 0.001f * sin(1000 * duration);
		if (position.x < -1000)
		{
			Die();
		}
		pollen_pink->Position(position);
		pollen_pink->Update(V, P);
		collider->World(pollen_pink->World(), Vector2(0.6f, 0.6f));
	}
	collider->Update(V, P);
}

void Pollen::Render()
{
	if(b_rand)
		pollen_white->Render();
	else
		pollen_pink->Render();
	//collider->Render();
}

void Pollen::Play()
{
	if(b_rand)
		pollen_pink->Play(0);
	else
		pollen_white->Play(0);
}

bool Pollen::IsPlayEnd()
{
	return false;
}

void Pollen::Spawn(Vector2 _position)
{
	b_rand = Math::Random(0, 1);
	b_live = true;
	position = _position;
	Play();
}

void Pollen::Die()
{
	b_live = false;
	StaticCollisionList::EraseEnemyObject(this);
}

bool Pollen::IsLive()
{
	return b_live;
}

void Pollen::CupheadPosition(Vector2 _position)
{
	cuphead_pos = _position;
}
