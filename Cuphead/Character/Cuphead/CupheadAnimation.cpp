#include "stdafx.h"
#include "CupheadAnimation.h"

CupheadAnimation::CupheadAnimation(Vector2 _position, Vector2 _scale)
	: Animation(_position, _scale)
{
	wstring shader_file = L"Cuphead.fx";
	Clip* clip;

	wstring idle = L"Player/Idle/cuphead_idle.png";
	{	// Idle
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(idle, shader_file, 0, 0, 98, 155), 0.1f);
		clip->AddFrame(new Sprite(idle, shader_file, 0, 155, 98, 307), 0.1f);
		clip->AddFrame(new Sprite(idle, shader_file, 0, 307, 98, 456), 0.1f);
		clip->AddFrame(new Sprite(idle, shader_file, 0, 456, 100, 599), 0.1f);
		clip->AddFrame(new Sprite(idle, shader_file, 0, 599, 97, 737), 0.1f);
		clip->AddFrame(new Sprite(idle, shader_file, 0, 456, 100, 599), 0.1f);
		clip->AddFrame(new Sprite(idle, shader_file, 0, 307, 98, 456), 0.1f);
		clip->AddFrame(new Sprite(idle, shader_file, 0, 155, 98, 307), 0.1f);
		AddClip(clip);
	}

	wstring run = L"Player/Run/Normal/cuphead_run.png";
	wstring run_shoot = L"Player/Run/Shooting/Straight/cuphead_run_shoot.png";
	wstring run_shoot_diagonal_up = L"Player/Run/Shooting/Diagonal Up/cuphead_run_shoot_diagonal_up.png";
	{	// RunNormal
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(run, shader_file, 0, 0, 135, 155), 0.1f);
		clip->AddFrame(new Sprite(run, shader_file, 0, 155, 122, 304), 0.1f);
		clip->AddFrame(new Sprite(run, shader_file, 0, 304, 113, 461), 0.1f);
		clip->AddFrame(new Sprite(run, shader_file, 0, 461, 109, 623), 0.1f);
		clip->AddFrame(new Sprite(run, shader_file, 0, 623, 110, 792), 0.1f);
		clip->AddFrame(new Sprite(run, shader_file, 0, 792, 112, 936), 0.1f);
		clip->AddFrame(new Sprite(run, shader_file, 0, 936, 122, 1082), 0.1f);
		clip->AddFrame(new Sprite(run, shader_file, 0, 1082, 130, 1228), 0.1f);
		clip->AddFrame(new Sprite(run, shader_file, 0, 1228, 122, 1378), 0.1f);
		clip->AddFrame(new Sprite(run, shader_file, 0, 1378, 114, 1524), 0.1f);
		clip->AddFrame(new Sprite(run, shader_file, 0, 1524, 113, 1673), 0.1f);
		clip->AddFrame(new Sprite(run, shader_file, 0, 1673, 115, 1823), 0.1f);
		clip->AddFrame(new Sprite(run, shader_file, 0, 1823, 120, 1968), 0.1f);
		clip->AddFrame(new Sprite(run, shader_file, 0, 1968, 118, 2110), 0.1f);
		clip->AddFrame(new Sprite(run, shader_file, 0, 2110, 128, 2254), 0.1f);
		clip->AddFrame(new Sprite(run, shader_file, 0, 2254, 137, 2407), 0.1f);
		AddClip(clip);
	}
	{	// RunNormalTurnaround
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(run, shader_file, 0, 2407, 132, 2571), 0.1f);
		clip->AddFrame(new Sprite(run, shader_file, 0, 2571, 125, 2735), 0.1f);
		AddClip(clip);
	}
	{	// RunShootingStraight
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(run_shoot, shader_file, 0, 0, 138, 155), 0.1f);
		clip->AddFrame(new Sprite(run_shoot, shader_file, 0, 155, 128, 301), 0.1f);
		clip->AddFrame(new Sprite(run_shoot, shader_file, 0, 301, 119, 449), 0.1f);
		clip->AddFrame(new Sprite(run_shoot, shader_file, 0, 449, 119, 604), 0.1f);
		clip->AddFrame(new Sprite(run_shoot, shader_file, 0, 604, 121, 766), 0.1f);
		clip->AddFrame(new Sprite(run_shoot, shader_file, 0, 766, 124, 923), 0.1f);
		clip->AddFrame(new Sprite(run_shoot, shader_file, 0, 923, 133, 1068), 0.1f);
		clip->AddFrame(new Sprite(run_shoot, shader_file, 0, 1068, 140, 1217), 0.1f);
		clip->AddFrame(new Sprite(run_shoot, shader_file, 0, 1217, 134, 1371), 0.1f);
		clip->AddFrame(new Sprite(run_shoot, shader_file, 0, 1371, 128, 1521), 0.1f);
		clip->AddFrame(new Sprite(run_shoot, shader_file, 0, 1521, 123, 1671), 0.1f);
		clip->AddFrame(new Sprite(run_shoot, shader_file, 0, 1671, 122, 1826), 0.1f);
		clip->AddFrame(new Sprite(run_shoot, shader_file, 0, 1826, 126, 1987), 0.1f);
		clip->AddFrame(new Sprite(run_shoot, shader_file, 0, 1987, 126, 2130), 0.1f);
		clip->AddFrame(new Sprite(run_shoot, shader_file, 0, 2130, 140, 2279), 0.1f);
		clip->AddFrame(new Sprite(run_shoot, shader_file, 0, 2279, 144, 2429), 0.1f);
		AddClip(clip);
	}
	{	// RunShootingStraightTurnaround
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(run_shoot, shader_file, 0, 2429, 137, 2593), 0.1f);
		clip->AddFrame(new Sprite(run_shoot, shader_file, 0, 2593, 135, 2768), 0.1f);
		AddClip(clip);
	}
	{	// RunShootingDiagonalUp
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(run_shoot_diagonal_up, shader_file, 0, 339, 142, 484), 0.1f);
		clip->AddFrame(new Sprite(run_shoot_diagonal_up, shader_file, 0, 484, 137, 624), 0.1f);
		clip->AddFrame(new Sprite(run_shoot_diagonal_up, shader_file, 0, 624, 133, 773), 0.1f);
		clip->AddFrame(new Sprite(run_shoot_diagonal_up, shader_file, 0, 773, 133, 926), 0.1f);
		clip->AddFrame(new Sprite(run_shoot_diagonal_up, shader_file, 0, 926, 126, 1083), 0.1f);
		clip->AddFrame(new Sprite(run_shoot_diagonal_up, shader_file, 0, 1083, 129, 1233), 0.1f);
		clip->AddFrame(new Sprite(run_shoot_diagonal_up, shader_file, 0, 1233, 133, 1368), 0.1f);
		clip->AddFrame(new Sprite(run_shoot_diagonal_up, shader_file, 0, 1368, 139, 1505), 0.1f);
		clip->AddFrame(new Sprite(run_shoot_diagonal_up, shader_file, 0, 1505, 137, 1646), 0.1f);
		clip->AddFrame(new Sprite(run_shoot_diagonal_up, shader_file, 0, 1646, 134, 1789), 0.1f);
		clip->AddFrame(new Sprite(run_shoot_diagonal_up, shader_file, 0, 1789, 134, 1938), 0.1f);
		clip->AddFrame(new Sprite(run_shoot_diagonal_up, shader_file, 0, 1938, 132, 2088), 0.1f);
		clip->AddFrame(new Sprite(run_shoot_diagonal_up, shader_file, 0, 2088, 130, 2243), 0.1f);
		clip->AddFrame(new Sprite(run_shoot_diagonal_up, shader_file, 0, 2243, 127, 2380), 0.1f);
		clip->AddFrame(new Sprite(run_shoot_diagonal_up, shader_file, 0, 2380, 134, 2514), 0.1f);
		clip->AddFrame(new Sprite(run_shoot_diagonal_up, shader_file, 0, 2514, 143, 2654), 0.1f);
		AddClip(clip);
	}
	{	// RunShootingDiagonalUpTurnaround
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(run_shoot_diagonal_up, shader_file, 0, 0, 142, 171), 0.1f);
		clip->AddFrame(new Sprite(run_shoot_diagonal_up, shader_file, 0, 171, 143, 339), 0.1f);
		AddClip(clip);
	}

	wstring jump = L"Player/Jump/Cuphead/cuphead_jump.png";
	{	// Jump
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(jump, shader_file, 0, 0, 77, 79), 0.1f);
		clip->AddFrame(new Sprite(jump, shader_file, 0, 79, 77, 186), 0.1f);
		clip->AddFrame(new Sprite(jump, shader_file, 0, 186, 82, 295), 0.1f);
		clip->AddFrame(new Sprite(jump, shader_file, 0, 295, 80, 398), 0.1f);
		clip->AddFrame(new Sprite(jump, shader_file, 0, 398, 81, 475), 0.1f);
		clip->AddFrame(new Sprite(jump, shader_file, 0, 475, 76, 573), 0.1f);
		clip->AddFrame(new Sprite(jump, shader_file, 0, 573, 88, 680), 0.1f);
		clip->AddFrame(new Sprite(jump, shader_file, 0, 680, 86, 784), 0.1f);
		AddClip(clip);
	}

	wstring duck = L"Player/Duck/Idle/cuphead_duck.png";
	wstring duck_shoot = L"Player/Duck/Shoot/cuphead_duck_shoot.png";
	{	// Duck
		clip = new Clip(PlayMode::Loop, 7);
		clip->AddFrame(new Sprite(duck, shader_file, 0, 0, 144, 122), 0.1f);
		clip->AddFrame(new Sprite(duck, shader_file, 0, 122, 167, 222), 0.1f);
		clip->AddFrame(new Sprite(duck, shader_file, 0, 222, 161, 298), 0.1f);
		clip->AddFrame(new Sprite(duck, shader_file, 0, 298, 164, 378), 0.1f);
		clip->AddFrame(new Sprite(duck, shader_file, 0, 378, 161, 463), 0.1f);
		clip->AddFrame(new Sprite(duck, shader_file, 0, 463, 162, 555), 0.1f);
		clip->AddFrame(new Sprite(duck, shader_file, 0, 555, 163, 647), 0.1f);
		// Duck -> Idle(idx[7])
		clip->AddFrame(new Sprite(duck, shader_file, 0, 647, 162, 715), 0.1f);
		clip->AddFrame(new Sprite(duck, shader_file, 0, 715, 164, 784), 0.1f);
		clip->AddFrame(new Sprite(duck, shader_file, 0, 784, 164, 858), 0.1f);
		clip->AddFrame(new Sprite(duck, shader_file, 0, 858, 162, 934), 0.1f);
		clip->AddFrame(new Sprite(duck, shader_file, 0, 934, 162, 1014), 0.1f);
		AddClip(clip);
	}
	{	// DuckTurn
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(duck, shader_file, 0, 1014, 168, 1089), 0.1f);
		AddClip(clip);
	}
	{	// DuckShoot
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(duck_shoot, shader_file, 0, 0, 178, 68), 0.1f);
		clip->AddFrame(new Sprite(duck_shoot, shader_file, 0, 68, 170, 138), 0.1f);
		clip->AddFrame(new Sprite(duck_shoot, shader_file, 0, 138, 146, 219), 0.1f);
		AddClip(clip);
	}

	wstring dash_ground = L"Player/Dash/Ground/cuphead_dash.png";
	wstring dash_air = L"Player/Dash/Air/cuphead_dash_air.png";
	{	// DashGround
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(dash_ground, shader_file, 0, 0, 102, 132), 0.1f);
		clip->AddFrame(new Sprite(dash_ground, shader_file, 0, 132, 156, 248), 0.1f);
		clip->AddFrame(new Sprite(dash_ground, shader_file, 0, 248, 254, 381), 0.1f);
		clip->AddFrame(new Sprite(dash_ground, shader_file, 0, 381, 273, 514), 0.1f);
		clip->AddFrame(new Sprite(dash_ground, shader_file, 0, 514, 290, 649), 0.1f);
		clip->AddFrame(new Sprite(dash_ground, shader_file, 0, 649, 312, 792), 0.1f);
		clip->AddFrame(new Sprite(dash_ground, shader_file, 0, 792, 326, 947), 0.1f);
		clip->AddFrame(new Sprite(dash_ground, shader_file, 0, 947, 227, 1110), 0.1f);
		AddClip(clip);
	}
	{	// DashAir
		clip = new Clip(PlayMode::End);
		clip->AddFrame(new Sprite(dash_air, shader_file, 0, 0, 101, 128), 0.1f);
		clip->AddFrame(new Sprite(dash_air, shader_file, 0, 128, 154, 250), 0.1f);
		clip->AddFrame(new Sprite(dash_air, shader_file, 0, 250, 252, 358), 0.1f);
		clip->AddFrame(new Sprite(dash_air, shader_file, 0, 358, 273, 465), 0.1f);
		clip->AddFrame(new Sprite(dash_air, shader_file, 0, 465, 290, 575), 0.1f);
		clip->AddFrame(new Sprite(dash_air, shader_file, 0, 575, 312, 690), 0.1f);
		clip->AddFrame(new Sprite(dash_air, shader_file, 0, 690, 326, 816), 0.1f);
		clip->AddFrame(new Sprite(dash_air, shader_file, 0, 816, 226, 951), 0.1f);
		AddClip(clip);
	}

	wstring shoot_up = L"Player/Shoot/Up/cuphead_shoot_up.png";
	wstring shoot_down = L"Player/Shoot/Down/cuphead_shoot_down.png";
	wstring shoot_straight = L"Player/Shoot/Straight/cuphead_shoot_straight.png";
	wstring shoot_diagonal_up = L"Player/Shoot/Diagonal Up/cuphead_shoot_diagonal_up.png";
	wstring shoot_diagonal_down = L"Player/Shoot/Diagonal Down/cuphead_shoot_diagonal_down.png";
	{	// ShootUp
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(shoot_up, shader_file, 0, 0, 108, 172), 0.1f);
		clip->AddFrame(new Sprite(shoot_up, shader_file, 0, 172, 105, 336), 0.1f);
		clip->AddFrame(new Sprite(shoot_up, shader_file, 0, 336, 105, 503), 0.1f);
		AddClip(clip);
	}
	{	// ShootDown
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(shoot_down, shader_file, 0, 0, 101, 169), 0.1f);
		clip->AddFrame(new Sprite(shoot_down, shader_file, 0, 169, 96, 324), 0.1f);
		clip->AddFrame(new Sprite(shoot_down, shader_file, 0, 324, 98, 483), 0.1f);
		AddClip(clip);
	}
	{	// ShootStraight
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(shoot_straight, shader_file, 0, 0, 126, 150), 0.1f);
		clip->AddFrame(new Sprite(shoot_straight, shader_file, 0, 150, 127, 307), 0.1f);
		clip->AddFrame(new Sprite(shoot_straight, shader_file, 0, 307, 118, 460), 0.1f);
		AddClip(clip);
	}
	{	// ShootDiagonalUp
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(shoot_diagonal_up, shader_file, 0, 0, 126, 150), 0.1f);
		clip->AddFrame(new Sprite(shoot_diagonal_up, shader_file, 0, 150, 122, 296), 0.1f);
		clip->AddFrame(new Sprite(shoot_diagonal_up, shader_file, 0, 296, 122, 445), 0.1f);
		AddClip(clip);
	}
	{	// ShootDiagonalDown
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(shoot_diagonal_down, shader_file, 0, 0, 117, 159), 0.1f);
		clip->AddFrame(new Sprite(shoot_diagonal_down, shader_file, 0, 159, 120, 315), 0.1f);
		clip->AddFrame(new Sprite(shoot_diagonal_down, shader_file, 0, 315, 120, 476), 0.1f);
		AddClip(clip);
	}

	wstring aim_up = L"Player/Aim/Up/cuphead_aim_up.png";
	wstring aim_down = L"Player/Aim/Down/cuphead_aim_down.png";
	wstring aim_straight = L"Player/Aim/Straight/cuphead_aim_straight.png";
	wstring aim_diagonal_up = L"Player/Aim/Diagonal Up/cuphead_aim_diagonal_up.png";
	wstring aim_diagonal_down = L"Player/Aim/Diagonal Down/cuphead_aim_diagonal_down.png";
	{	// AimUp
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(aim_up, shader_file, 0, 0, 106, 175), 0.1f);
		clip->AddFrame(new Sprite(aim_up, shader_file, 0, 175, 108, 349), 0.1f);
		clip->AddFrame(new Sprite(aim_up, shader_file, 0, 349, 106, 517), 0.1f);
		clip->AddFrame(new Sprite(aim_up, shader_file, 0, 517, 107, 681), 0.1f);
		clip->AddFrame(new Sprite(aim_up, shader_file, 0, 681, 105, 843), 0.1f);
		AddClip(clip);
	}
	{	// AimDown
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(aim_down, shader_file, 0, 0, 99, 168), 0.1f);
		clip->AddFrame(new Sprite(aim_down, shader_file, 0, 168, 98, 333), 0.1f);
		clip->AddFrame(new Sprite(aim_down, shader_file, 0, 333, 103, 495), 0.1f);
		clip->AddFrame(new Sprite(aim_down, shader_file, 0, 495, 99, 654), 0.1f);
		clip->AddFrame(new Sprite(aim_down, shader_file, 0, 654, 100, 806), 0.1f);
		AddClip(clip);
	}
	{	// AimStraight
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(aim_straight, shader_file, 0, 0, 129, 152), 0.1f);
		clip->AddFrame(new Sprite(aim_straight, shader_file, 0, 152, 133, 313), 0.1f);
		clip->AddFrame(new Sprite(aim_straight, shader_file, 0, 313, 134, 469), 0.1f);
		clip->AddFrame(new Sprite(aim_straight, shader_file, 0, 469, 130, 610), 0.1f);
		clip->AddFrame(new Sprite(aim_straight, shader_file, 0, 610, 131, 746), 0.1f);
		AddClip(clip);
	}
	{	// AimDiagonalUp
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(aim_diagonal_up, shader_file, 0, 0, 129, 151), 0.1f);
		clip->AddFrame(new Sprite(aim_diagonal_up, shader_file, 0, 151, 127, 299), 0.1f);
		clip->AddFrame(new Sprite(aim_diagonal_up, shader_file, 0, 299, 128, 443), 0.1f);
		clip->AddFrame(new Sprite(aim_diagonal_up, shader_file, 0, 443, 129, 583), 0.1f);
		clip->AddFrame(new Sprite(aim_diagonal_up, shader_file, 0, 583, 126, 716), 0.1f);
		AddClip(clip);
	}
	{	// AimDiagonalDown
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(aim_diagonal_down, shader_file, 0, 0, 118, 163), 0.1f);
		clip->AddFrame(new Sprite(aim_diagonal_down, shader_file, 0, 163, 117, 321), 0.1f);
		clip->AddFrame(new Sprite(aim_diagonal_down, shader_file, 0, 321, 117, 477), 0.1f);
		clip->AddFrame(new Sprite(aim_diagonal_down, shader_file, 0, 477, 116, 624), 0.1f);
		clip->AddFrame(new Sprite(aim_diagonal_down, shader_file, 0, 624, 116, 766), 0.1f);
		AddClip(clip);
	}

	wstring death = L"Player/Death/cuphead_death_body.png";
	{	// Death
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(aim_diagonal_down, shader_file, 0, 0  , 152, 90), 0.1f);
		clip->AddFrame(new Sprite(aim_diagonal_down, shader_file, 0, 90, 172, 196), 0.1f);
		clip->AddFrame(new Sprite(aim_diagonal_down, shader_file, 0, 196, 165, 295), 0.1f);
		clip->AddFrame(new Sprite(aim_diagonal_down, shader_file, 0, 295, 157, 388), 0.1f);
		clip->AddFrame(new Sprite(aim_diagonal_down, shader_file, 0, 388, 158, 480), 0.1f);
		clip->AddFrame(new Sprite(aim_diagonal_down, shader_file, 0, 480, 151, 568), 0.1f);
		clip->AddFrame(new Sprite(aim_diagonal_down, shader_file, 0, 568, 148, 657), 0.1f);
		clip->AddFrame(new Sprite(aim_diagonal_down, shader_file, 0, 657, 149, 743), 0.1f);
		clip->AddFrame(new Sprite(aim_diagonal_down, shader_file, 0, 743, 147, 827), 0.1f);
		clip->AddFrame(new Sprite(aim_diagonal_down, shader_file, 0, 827, 146, 912), 0.1f);
		clip->AddFrame(new Sprite(aim_diagonal_down, shader_file, 0, 912, 146, 999), 0.1f);
		clip->AddFrame(new Sprite(aim_diagonal_down, shader_file, 0, 999, 140, 1085), 0.1f);
		clip->AddFrame(new Sprite(aim_diagonal_down, shader_file, 0, 1085, 137, 1166), 0.1f);
		clip->AddFrame(new Sprite(aim_diagonal_down, shader_file, 0, 1166, 138, 1247), 0.1f);
		clip->AddFrame(new Sprite(aim_diagonal_down, shader_file, 0, 1247, 136, 1327), 0.1f);
		clip->AddFrame(new Sprite(aim_diagonal_down, shader_file, 0, 1327, 126, 1407), 0.1f);
		AddClip(clip);
	}

	wstring hit_air = L"Player/Hit/Air/cuphead_hit_air.png";
	wstring hit_ground = L"Player/Hit/Ground/cuphead_hit.png";
	{	// HitAir
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(hit_air, shader_file, 0, 0, 118, 170), 0.1f);
		clip->AddFrame(new Sprite(hit_air, shader_file, 0, 170, 125, 346), 0.1f);
		clip->AddFrame(new Sprite(hit_air, shader_file, 0, 346, 119, 534), 0.1f);
		clip->AddFrame(new Sprite(hit_air, shader_file, 0, 534, 122, 712), 0.1f);
		clip->AddFrame(new Sprite(hit_air, shader_file, 0, 712, 124, 889), 0.1f);
		clip->AddFrame(new Sprite(hit_air, shader_file, 0, 889, 121, 1057), 0.1f);
		AddClip(clip);
	}
	{	// HitGround
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(hit_ground, shader_file, 0, 0, 117, 190), 0.1f);
		clip->AddFrame(new Sprite(hit_ground, shader_file, 0, 190, 125, 396), 0.1f);
		clip->AddFrame(new Sprite(hit_ground, shader_file, 0, 396, 119, 617), 0.1f);
		clip->AddFrame(new Sprite(hit_ground, shader_file, 0, 617, 121, 831), 0.1f);
		clip->AddFrame(new Sprite(hit_ground, shader_file, 0, 831, 122, 1036), 0.1f);
		clip->AddFrame(new Sprite(hit_ground, shader_file, 0, 1036, 120, 1227), 0.1f);
		AddClip(clip);
	}

	wstring intro_textrue = L"Player/Intro/cuphead_intro_a.png";
	{	// Intro
		clip = new Clip(PlayMode::End);
		clip->AddFrame(new Sprite(intro_textrue, shader_file, 0, 0, 97, 152), 0.08f);
		clip->AddFrame(new Sprite(intro_textrue, shader_file, 0, 152, 97, 305), 0.08f);
		clip->AddFrame(new Sprite(intro_textrue, shader_file, 0, 305, 98, 458), 0.08f);
		clip->AddFrame(new Sprite(intro_textrue, shader_file, 0, 458, 101, 608), 0.08f);
		clip->AddFrame(new Sprite(intro_textrue, shader_file, 0, 608, 104, 757), 0.08f);
		clip->AddFrame(new Sprite(intro_textrue, shader_file, 0, 757, 94, 908), 0.08f);
		clip->AddFrame(new Sprite(intro_textrue, shader_file, 0, 908, 98, 1062), 0.08f);
		clip->AddFrame(new Sprite(intro_textrue, shader_file, 0, 1062, 98, 1218), 0.08f);
		clip->AddFrame(new Sprite(intro_textrue, shader_file, 0, 1218, 100, 1376), 0.08f);
		clip->AddFrame(new Sprite(intro_textrue, shader_file, 0, 1376, 108, 1539), 0.08f);
		clip->AddFrame(new Sprite(intro_textrue, shader_file, 0, 1539, 110, 1696), 0.08f);
		clip->AddFrame(new Sprite(intro_textrue, shader_file, 0, 1696, 118, 1856), 0.08f);
		clip->AddFrame(new Sprite(intro_textrue, shader_file, 0, 1856, 113, 2017), 0.08f);
		clip->AddFrame(new Sprite(intro_textrue, shader_file, 0, 2017, 114, 2176), 0.08f);
		clip->AddFrame(new Sprite(intro_textrue, shader_file, 0, 2176, 110, 2338), 0.08f);
		clip->AddFrame(new Sprite(intro_textrue, shader_file, 0, 2338, 108, 2498), 0.08f);
		clip->AddFrame(new Sprite(intro_textrue, shader_file, 0, 2498, 106, 2663), 0.08f);
		clip->AddFrame(new Sprite(intro_textrue, shader_file, 0, 2663, 108, 2828), 0.08f);
		clip->AddFrame(new Sprite(intro_textrue, shader_file, 0, 2828, 105, 2993), 0.08f);
		clip->AddFrame(new Sprite(intro_textrue, shader_file, 0, 2993, 100, 3159), 0.08f);
		clip->AddFrame(new Sprite(intro_textrue, shader_file, 0, 3159, 113, 3323), 0.08f);
		clip->AddFrame(new Sprite(intro_textrue, shader_file, 0, 3323, 138, 3487), 0.08f);
		clip->AddFrame(new Sprite(intro_textrue, shader_file, 0, 3487, 149, 3650), 0.08f);
		clip->AddFrame(new Sprite(intro_textrue, shader_file, 0, 3650, 143, 3808), 0.08f);
		clip->AddFrame(new Sprite(intro_textrue, shader_file, 0, 3808, 124, 3961), 0.08f);
		clip->AddFrame(new Sprite(intro_textrue, shader_file, 0, 3961, 107, 4110), 0.08f);
		clip->AddFrame(new Sprite(intro_textrue, shader_file, 0, 4110, 100, 4260), 0.08f);
		clip->AddFrame(new Sprite(intro_textrue, shader_file, 0, 4260, 96, 4410 ), 0.08f);
		AddClip(clip);
	}

	jump_dust_fx = make_unique<Clip>(PlayMode::Once);
	wstring jdf = L"Player/Jump/Dust/cuphead_jump_dust_a.png";
	jump_dust_fx->AddFrame(new Sprite(jdf, shader_file, 0, 0, 110, 38), 0.1f);
	jump_dust_fx->AddFrame(new Sprite(jdf, shader_file, 0, 38, 165, 103), 0.1f);
	jump_dust_fx->AddFrame(new Sprite(jdf, shader_file, 0, 103, 178, 187), 0.1f);
	jump_dust_fx->AddFrame(new Sprite(jdf, shader_file, 0, 187, 195, 300), 0.1f);
	jump_dust_fx->AddFrame(new Sprite(jdf, shader_file, 0, 300, 218, 413), 0.1f);
	jump_dust_fx->AddFrame(new Sprite(jdf, shader_file, 0, 413, 234, 539), 0.1f);
	jump_dust_fx->AddFrame(new Sprite(jdf, shader_file, 0, 539, 238, 670), 0.1f);
	jump_dust_fx->AddFrame(new Sprite(jdf, shader_file, 0, 670, 245, 799), 0.1f);
	jump_dust_fx->AddFrame(new Sprite(jdf, shader_file, 0, 799, 249, 951), 0.1f);
	jump_dust_fx->AddFrame(new Sprite(jdf, shader_file, 0, 951, 255, 1096), 0.1f);
	jump_dust_fx->AddFrame(new Sprite(jdf, shader_file, 0, 1096, 265, 1230), 0.1f);
	jump_dust_fx->AddFrame(new Sprite(jdf, shader_file, 0, 1230, 274, 1363), 0.1f);
	jump_dust_fx->AddFrame(new Sprite(jdf, shader_file, 0, 1363, 282, 1490), 0.1f);
	jump_dust_fx->AddFrame(new Sprite(jdf, shader_file, 0, 1490, 285, 1623), 0.1f);
}

void CupheadAnimation::Play(CUPHEAD_STATE state)
{
	Animation::Play((UINT)state);
}
