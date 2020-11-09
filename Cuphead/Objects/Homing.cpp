#include "stdafx.h"
#include "Homing.h"

Homing::Homing(Vector2 _position, Vector2 _scale)
	: Weapon(_position, _scale)
{
	wstring homing_texture = L"Player/Weapon/Weapon_Homing.png";
	clip = make_unique<Clip>(PlayMode::Loop);
	clip->AddFrame(new Sprite(homing_texture, shader_file, 20, 177, 66, 237), 0.1f);
	clip->AddFrame(new Sprite(homing_texture, shader_file, 77, 182, 130, 236), 0.1f);
	clip->AddFrame(new Sprite(homing_texture, shader_file, 140, 179, 182, 237), 0.1f);
	clip->AddFrame(new Sprite(homing_texture, shader_file, 191, 191, 229, 237), 0.1f);
	clip->AddFrame(new Sprite(homing_texture, shader_file, 246, 188, 280, 238), 0.1f);
	clip->AddFrame(new Sprite(homing_texture, shader_file, 298, 187, 337, 239), 0.1f);
	clip->AddFrame(new Sprite(homing_texture, shader_file, 358, 182, 401, 238), 0.1f);

	fireFX = make_unique<Clip>(PlayMode::Once);
	//HX 추가 호밍 이펙트
	hitFX = make_unique<Clip>(PlayMode::Once);
}

void Homing::Update(Matrix & V, Matrix & P)
{
	if (bStop == false)
	{
		position.x += direction * homing_speed * Time::Delta();

		if (direction < 0)
			clip->Rotation(0, Math::PI, 0);
		else
			clip->Rotation(0, 0, 0);
		// set bullet left bound, right bound
		if (position.x > right_bound || position.x < left_bound)
			Stop();
	}
	//HX choose update or not
	clip->Position(position);
	clip->Update(V, P);
	fireFX->Position(fireFX_pos);
	fireFX->Update(V, P);
	hitFX->Position(hitFX_pos);
	hitFX->Update(V, P);
	collider->World(clip->World());
	collider->Update(V, P);
}

void Homing::Render()
{
	fireFX->Render();
	hitFX->Render();
	clip->Render();
	//HX choose render or not
	collider->Render();
}

void Homing::Shoot(Vector2 _position, float _forwardVector)
{
	Vector2 shootPos = { _position.x + (55 * _forwardVector), _position.y };
	direction = _forwardVector;
	position = shootPos;
	fireFX_pos = Vector2(shootPos.x + 5, shootPos.y - 20);
	clip->Position(shootPos);
	clip->Play(0, repeat_idx);
	fireFX->Play(0);
	bStop = false;
}

void Homing::Stop()
{
	hitFX_pos = Vector2(position.x + direction * 50, position.y - 50);
	hitFX->Play(0);
	position = Vector2(-500, -500);
	bStop = true;
}