#pragma once
#include "stdafx.h"

class Platform
{
public:
	Platform(Vector2 _position, Vector2 _scale)
		: position(_position), scale(_scale),
		propellor_pos(_position), shadow_pos(_position),
		duration(0)
	{
		collider = make_unique<Collider>();

		shader_file = L"Effect.fx";
		platform_texture = L"Bosses/Cagney Carnation/Platform/Carnation_Platform.png";

		propellor = make_unique<Clip>(PlayMode::Loop);
		propellor->AddFrame(new Sprite(platform_texture, shader_file, 0, 815, 109, 851), 0.1f);
		propellor->AddFrame(new Sprite(platform_texture, shader_file, 0, 851, 115, 890), 0.1f);
		propellor->AddFrame(new Sprite(platform_texture, shader_file, 0, 890, 107, 925), 0.1f);
		propellor->AddFrame(new Sprite(platform_texture, shader_file, 0, 925, 110, 960), 0.1f);
		propellor->AddFrame(new Sprite(platform_texture, shader_file, 0, 960, 114, 996), 0.1f);
		propellor->AddFrame(new Sprite(platform_texture, shader_file, 0, 996, 111, 1031), 0.1f);
		propellor->AddFrame(new Sprite(platform_texture, shader_file, 0, 1031, 117, 1067), 0.1f);
		propellor->AddFrame(new Sprite(platform_texture, shader_file, 0, 1067, 113, 1103), 0.1f);
		propellor->AddFrame(new Sprite(platform_texture, shader_file, 0, 1103, 110, 1139), 0.1f);
		propellor->Position(_position);
		propellor->Scale(_scale);

		shadow_fx = make_unique<Clip>(PlayMode::Loop);
		shadow_fx->AddFrame(new Sprite(platform_texture, shader_file, 0, 1139, 93, 1157), 0.1f);
		shadow_fx->AddFrame(new Sprite(platform_texture, shader_file, 0, 1157, 91, 1177), 0.1f);
		shadow_fx->AddFrame(new Sprite(platform_texture, shader_file, 0, 1177, 90, 1198), 0.1f);
		shadow_fx->Position(_position);
		shadow_fx->Scale(_scale);
	}
	virtual ~Platform() = default;
	void Position(Vector2 vec) { position = vec; }
	Vector2 Position() { return position; }

public:
	virtual void Update(Matrix& V, Matrix& P) = 0;
	virtual void Render() = 0;
	virtual void Play() = 0;

protected:
	unique_ptr<Collider> collider;
	unique_ptr<Clip> propellor;
	unique_ptr<Clip> shadow_fx;
	Vector2 position;
	Vector2 scale;
	Vector2 propellor_pos;
	Vector2 shadow_pos;
	wstring shader_file;
	wstring platform_texture;
	float duration;
};