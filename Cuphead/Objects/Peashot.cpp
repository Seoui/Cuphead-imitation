#include "stdafx.h"
#include "Peashot.h"

Peashot::Peashot(Vector2 _position, Vector2 _scale)
	: Weapon(_position, _scale)
{
	wstring peashot_texture = L"Player/Weapon/Weapon_Peashot.png";
	clip = make_unique<Clip>(PlayMode::Loop);
	clip->AddFrame(new Sprite(peashot_texture, shader_file, 50, 440, 94, 477), 0.04f);
	clip->AddFrame(new Sprite(peashot_texture, shader_file, 130, 439, 183, 478), 0.04f);
	clip->AddFrame(new Sprite(peashot_texture, shader_file, 222, 442, 274, 479), 0.06f);
	clip->AddFrame(new Sprite(peashot_texture, shader_file, 310, 439, 385, 479), 0.06f);
	clip->AddFrame(new Sprite(peashot_texture, shader_file, 422, 439, 502, 479), 0.06f);
	clip->AddFrame(new Sprite(peashot_texture, shader_file, 541, 437, 630, 474), 0.1f);
	clip->AddFrame(new Sprite(peashot_texture, shader_file, 685, 438, 808, 475), 0.1f);
	clip->AddFrame(new Sprite(peashot_texture, shader_file, 870, 439, 1002, 479), 0.1f);
	clip->AddFrame(new Sprite(peashot_texture, shader_file, 1061, 440, 1207, 480), 0.1f);
	clip->AddFrame(new Sprite(peashot_texture, shader_file, 1274, 441, 1432, 488), 0.1f);
	clip->AddFrame(new Sprite(peashot_texture, shader_file, 1494, 442, 1650, 483), 0.1f);
	clip->AddFrame(new Sprite(peashot_texture, shader_file, 1698, 448, 1841, 487), 0.1f);
	
	fireFX = make_unique<Clip>(PlayMode::Once);
	fireFX->AddFrame(new Sprite(peashot_texture, shader_file, 210, 111, 267, 180), 0.03f);
	fireFX->AddFrame(new Sprite(peashot_texture, shader_file, 512, 105, 576, 183), 0.03f);
	fireFX->AddFrame(new Sprite(peashot_texture, shader_file, 46, 101, 137, 188), 0.03f);
	fireFX->AddFrame(new Sprite(peashot_texture, shader_file, 337, 73, 453, 188), 0.03f);

	hitFX = make_unique<Clip>(PlayMode::Once);
	hitFX->AddFrame(new Sprite(peashot_texture, shader_file, 53, 779, 133, 847), 0.05f);
	hitFX->AddFrame(new Sprite(peashot_texture, shader_file, 196, 765, 287, 848), 0.05f);
	hitFX->AddFrame(new Sprite(peashot_texture, shader_file, 357, 721, 519, 884), 0.05f);
	hitFX->AddFrame(new Sprite(peashot_texture, shader_file, 601, 682, 833, 921), 0.05f);
	hitFX->AddFrame(new Sprite(peashot_texture, shader_file, 907, 666, 1158, 936), 0.05f);
	hitFX->AddFrame(new Sprite(peashot_texture, shader_file, 1224, 662, 1484, 941), 0.05f);
}

void Peashot::Update(Matrix & V, Matrix & P)
{
	if (bStop == false)
	{
		position += dir * peashot_speed * Time::Delta();
		//position.x += direction * peashot_speed * Time::Delta();

		if (dir.x < 0 && dir.y < 1)
			clip->Rotation(0, Math::PI, 0);
		else if( dir.x > 0 && dir.y <1)
			clip->Rotation(0, 0, 0);
		//HX set bullet left bound, right bound
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
	collider->World(clip->World(), Vector2(1.0f, 1.0f));
	collider->Update(V, P);
}

void Peashot::Render()
{
	fireFX->Render();
	hitFX->Render();
	clip->Render();
	//HX choose render or not
	//collider->Render();
}

void Peashot::Shoot(Vector2 _position, float _forwardVector)
{
	Vector2 shootPos = { _position.x + (55 * _forwardVector), _position.y };
	dir = Vector2(_forwardVector, 0);
	//direction = _forwardVector;
	position = shootPos;
	fireFX_pos = Vector2(shootPos.x + 5, shootPos.y - 20);
	clip->Position(shootPos);
	clip->Play(0, repeat_idx);
	fireFX->Play(0);
	bStop = false;
}

void Peashot::Stop()
{
	hitFX_pos = Vector2(position.x + direction * 50, position.y - 50);
	hitFX->Play(0);
	position = Vector2(-1000, -1000);
	bStop = true;
}

void Peashot::ShootUp(Vector2 _position, float forwardVector)
{
	Vector2 shootPos;
	if(forwardVector > 0)
		shootPos = { _position.x + 30, _position.y + 70 };
	else
		shootPos = { _position.x - 30, _position.y + 70 };
	rotation.z = Math::PI * 0.5f;
	dir = Vector2(0, 1);
	position = shootPos;
	fireFX_pos = Vector2(shootPos.x + 5, shootPos.y - 20);
	fireFX->Play(0);
	bStop = false;
	clip->Rotation(rotation);
	clip->Position(shootPos);
	clip->Play(0, repeat_idx);
}
