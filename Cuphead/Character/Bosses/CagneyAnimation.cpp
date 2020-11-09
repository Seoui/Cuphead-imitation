#include "stdafx.h"
#include "CagneyAnimation.h"

CagneyAnimation::CagneyAnimation(Vector2 _position, Vector2 _scale)
	: Animation(_position, _scale)
{
	wstring shader_file = L"Cagney.fx";
	Clip* clip;

	wstring intro = L"Bosses/Cagney Carnation/Intro/Cagney_intro.png";
	{	// Intro
		clip = new Clip(PlayMode::End);
		Sprite* frame1 = new Sprite(intro, shader_file, 0, 0, 292, 546);
		Sprite* frame2 = new Sprite(intro, shader_file, 0, 546, 291, 1094);
		Sprite* frame3 = new Sprite(intro, shader_file, 0, 1094, 294, 1640);
		Sprite* frame4 = new Sprite(intro, shader_file, 0, 1640, 294, 2177);
		Sprite* frame5 = new Sprite(intro, shader_file, 0, 2177, 298, 2690);
		Sprite* frame6 = new Sprite(intro, shader_file, 0, 2690, 313, 3186);
		Sprite* frame7 = new Sprite(intro, shader_file, 0, 3186, 372, 3711);
		Sprite* frame8 = new Sprite(intro, shader_file, 0, 3711, 404, 4263);
		Sprite* frame9 = new Sprite(intro, shader_file, 0, 4263, 519, 4889);
		Sprite* frame10 = new Sprite(intro, shader_file, 0, 4889, 753, 5567);
		Sprite* frame11 = new Sprite(intro, shader_file, 0, 5567, 815, 6288);
		Sprite* frame12 = new Sprite(intro, shader_file, 0, 6288, 812, 6999);
		Sprite* frame13 = new Sprite(intro, shader_file, 0, 6999, 781, 7710);
		Sprite* frame14 = new Sprite(intro, shader_file, 0, 7710, 761, 8425);
		Sprite* frame15 = new Sprite(intro, shader_file, 0, 8425, 718, 9106);
		Sprite* frame16 = new Sprite(intro, shader_file, 0, 9106, 793, 9717);
		Sprite* frame17 = new Sprite(intro, shader_file, 0, 9717, 598, 10304);
		Sprite* frame18 = new Sprite(intro, shader_file, 0, 10304, 579, 10890);
		Sprite* frame19 = new Sprite(intro, shader_file, 0, 10890, 551, 11502);
		Sprite* frame20 = new Sprite(intro, shader_file, 0, 11502, 533, 12115);
		clip->AddFrame(frame1, 0.07f);
		clip->AddFrame(frame2, 0.07f);
		clip->AddFrame(frame3, 0.07f);
		clip->AddFrame(frame1, 0.07f);
		clip->AddFrame(frame2, 0.07f);
		clip->AddFrame(frame3, 0.07f);
		clip->AddFrame(frame1, 0.07f);
		clip->AddFrame(frame2, 0.07f);
		clip->AddFrame(frame3, 0.07f);
		clip->AddFrame(frame4, 0.07f);
		clip->AddFrame(frame5, 0.07f);
		clip->AddFrame(frame6, 0.07f);
		clip->AddFrame(frame7, 0.07f);
		clip->AddFrame(frame8, 0.07f);
		clip->AddFrame(frame9, 0.07f);
		clip->AddFrame(frame10, 0.07f);
		clip->AddFrame(frame11, 0.07f);
		clip->AddFrame(frame12, 0.07f);
		clip->AddFrame(frame13, 0.07f);
		clip->AddFrame(frame14, 0.07f);
		clip->AddFrame(frame10, 0.07f);
		clip->AddFrame(frame11, 0.07f);
		clip->AddFrame(frame12, 0.07f);
		clip->AddFrame(frame13, 0.07f);
		clip->AddFrame(frame14, 0.07f);
		clip->AddFrame(frame15, 0.06f);
		clip->AddFrame(frame16, 0.06f);
		clip->AddFrame(frame17, 0.06f);
		clip->AddFrame(frame18, 0.06f);
		clip->AddFrame(frame19, 0.06f);
		clip->AddFrame(frame20, 0.06f);
		AddClip(clip);
	}

	wstring idle = L"Bosses/Cagney Carnation/Idle/Cagney_idle.png";
	{	// Idle
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(idle, shader_file, 0, 0, 510, 616),       0.06f);
		clip->AddFrame(new Sprite(idle, shader_file, 0, 616, 488, 1246),    0.06f);
		clip->AddFrame(new Sprite(idle, shader_file, 0, 1246, 481, 1893),   0.06f);
		clip->AddFrame(new Sprite(idle, shader_file, 0, 1893, 470, 2552),   0.06f);
		clip->AddFrame(new Sprite(idle, shader_file, 0, 2552, 451, 3225),   0.06f);
		clip->AddFrame(new Sprite(idle, shader_file, 0, 3225, 410, 3889),   0.06f);
		clip->AddFrame(new Sprite(idle, shader_file, 0, 3889, 367, 4538),   0.06f);
		clip->AddFrame(new Sprite(idle, shader_file, 0, 4538, 335, 5173),   0.06f);
		clip->AddFrame(new Sprite(idle, shader_file, 0, 5173, 314, 5797),   0.06f);
		clip->AddFrame(new Sprite(idle, shader_file, 0, 5797, 304, 6414),   0.06f);
		clip->AddFrame(new Sprite(idle, shader_file, 0, 6414, 305, 7035),   0.06f);
		clip->AddFrame(new Sprite(idle, shader_file, 0, 7035, 329, 7662),   0.06f);
		clip->AddFrame(new Sprite(idle, shader_file, 0, 7662, 329, 8303),   0.06f);
		clip->AddFrame(new Sprite(idle, shader_file, 0, 8303, 356, 8952),   0.06f);
		clip->AddFrame(new Sprite(idle, shader_file, 0, 8952, 393, 9593),   0.06f);
		clip->AddFrame(new Sprite(idle, shader_file, 0, 9593, 447, 10219),  0.06f);
		clip->AddFrame(new Sprite(idle, shader_file, 0, 10219, 448, 10845), 0.06f);
		clip->AddFrame(new Sprite(idle, shader_file, 0, 10845, 485, 11472), 0.06f);
		clip->AddFrame(new Sprite(idle, shader_file, 0, 11472, 504, 12094), 0.06f);
		AddClip(clip);
	}

	wstring face_attack_high = L"Bosses/Cagney Carnation/Face Attack/Cagney_faceattack_high.png";
	{	// Face attack high
		clip = new Clip(PlayMode::End);
		clip->AddFrame(new Sprite(face_attack_high, shader_file, 0, 0, 340, 626),       0.07f);
		clip->AddFrame(new Sprite(face_attack_high, shader_file, 0, 626, 368, 1213),    0.07f);
		clip->AddFrame(new Sprite(face_attack_high, shader_file, 0, 1213, 380, 1774),   0.07f);
		clip->AddFrame(new Sprite(face_attack_high, shader_file, 0, 1774, 394, 2325),   0.07f);

		Sprite* frame5 = new Sprite(face_attack_high, shader_file, 0, 2325, 396, 2864);
		Sprite* frame6 = new Sprite(face_attack_high, shader_file, 0, 2864, 394, 3398);
		for (int i = 0; i < 6; ++i)
		{
			clip->AddFrame(frame5, 0.07f);
			clip->AddFrame(frame6, 0.07f);//16
		}
		clip->AddFrame(new Sprite(face_attack_high, shader_file, 0, 3398, 316, 3962),   0.07f);
		clip->AddFrame(new Sprite(face_attack_high, shader_file, 0, 3962, 451, 4552),   0.07f);
		clip->AddFrame(new Sprite(face_attack_high, shader_file, 0, 4552, 550, 5216),   0.07f);
		clip->AddFrame(new Sprite(face_attack_high, shader_file, 0, 5216, 677, 5876),   0.07f);

		Sprite* frame11 = new Sprite(face_attack_high, shader_file, 0, 5876, 1135, 6516);
		Sprite* frame12 = new Sprite(face_attack_high, shader_file, 0, 6516, 1141, 7172);
		Sprite* frame13 = new Sprite(face_attack_high, shader_file, 0, 7172, 1150, 7797);
		Sprite* frame14 = new Sprite(face_attack_high, shader_file, 0, 7797, 1149, 8454);
		for (int i = 0; i < 4; ++i)
		{
			clip->AddFrame(frame11, 0.07f);
			clip->AddFrame(frame12, 0.07f);
			clip->AddFrame(frame13, 0.07f);
			clip->AddFrame(frame14, 0.07f); //36
		}
	
		clip->AddFrame(new Sprite(face_attack_high, shader_file, 0, 8454, 1041, 9112),  0.07f);
		clip->AddFrame(new Sprite(face_attack_high, shader_file, 0, 9112, 989, 9754),   0.07f);
		clip->AddFrame(new Sprite(face_attack_high, shader_file, 0, 9754, 458, 10419),  0.07f);
		clip->AddFrame(new Sprite(face_attack_high, shader_file, 0, 10419, 347, 11066), 0.07f);
		clip->AddFrame(new Sprite(face_attack_high, shader_file, 0, 11066, 325, 11709), 0.07f);
		AddClip(clip);
	}

	wstring face_attack_low = L"Bosses/Cagney Carnation/Face Attack/Cagney_faceattack_low.png";
	{	// Face attack low
		clip = new Clip(PlayMode::End);
		clip->AddFrame(new Sprite(face_attack_low, shader_file, 0, 0,    300, 604),   0.07f);
		clip->AddFrame(new Sprite(face_attack_low, shader_file, 0, 604, 346, 1090),   0.07f);
		clip->AddFrame(new Sprite(face_attack_low, shader_file, 0, 1090, 363, 1495),  0.07f);
		clip->AddFrame(new Sprite(face_attack_low, shader_file, 0, 1495, 368, 1879),  0.07f);

		Sprite* frame5 = new Sprite(face_attack_low, shader_file, 0, 1879, 369, 2248);
		Sprite* frame6 = new Sprite(face_attack_low, shader_file, 0, 2248, 357, 2612);
		for (int i = 0; i < 6; ++i)
		{
			clip->AddFrame(frame5, 0.07f);
			clip->AddFrame(frame6, 0.07f);
		}
		
		clip->AddFrame(new Sprite(face_attack_low, shader_file, 0, 2612, 354, 2973),  0.07f);
		clip->AddFrame(new Sprite(face_attack_low, shader_file, 0, 2973, 384, 3335),  0.07f);
		clip->AddFrame(new Sprite(face_attack_low, shader_file, 0, 3335, 581, 3769),  0.07f);
		clip->AddFrame(new Sprite(face_attack_low, shader_file, 0, 3769, 723, 4215),  0.07f);

		Sprite* frame11 = new Sprite(face_attack_low, shader_file, 0, 4215, 1221, 4623);
		Sprite* frame12 = new Sprite(face_attack_low, shader_file, 0, 4623, 1245, 5015);
		Sprite* frame13 = new Sprite(face_attack_low, shader_file, 0, 5015, 1232, 5414);
		Sprite* frame14 = new Sprite(face_attack_low, shader_file, 0, 5414, 1224, 5803);
		for (int i = 0; i < 4; ++i)
		{
			clip->AddFrame(frame11, 0.07f);
			clip->AddFrame(frame12, 0.07f);
			clip->AddFrame(frame13, 0.07f);
			clip->AddFrame(frame14, 0.07f);
		}
	
		clip->AddFrame(new Sprite(face_attack_low, shader_file, 0, 5803, 1169, 6203), 0.07f);
		clip->AddFrame(new Sprite(face_attack_low, shader_file, 0, 6203, 1103, 6698), 0.07f);
		clip->AddFrame(new Sprite(face_attack_low, shader_file, 0, 6698, 667, 7268),  0.07f);
		clip->AddFrame(new Sprite(face_attack_low, shader_file, 0, 7268, 567, 7841),  0.07f);
		clip->AddFrame(new Sprite(face_attack_low, shader_file, 0, 7841, 518, 8444),  0.07f);
		clip->AddFrame(new Sprite(face_attack_low, shader_file, 0, 8444, 608,  9052), 0.07f);
		AddClip(clip);
	}

	wstring create_object = L"Bosses/Cagney Carnation/Creating Object/Cagney_create.png";
	{	// Create object
		clip = new Clip(PlayMode::End);
		Sprite* frame11 = new Sprite(create_object, shader_file, 0, 6171, 603, 6779);
		Sprite* frame12 = new Sprite(create_object, shader_file, 0, 6779, 605, 7383);
		Sprite* frame13 = new Sprite(create_object, shader_file, 0, 7383, 601, 7990);
		Sprite* frame14 = new Sprite(create_object, shader_file, 0, 7990, 598, 8592);
		Sprite* frame15 = new Sprite(create_object, shader_file, 0, 8592, 576, 9203);
		Sprite* frame16 = new Sprite(create_object, shader_file, 0, 9203, 547, 9831);
		Sprite* frame17 = new Sprite(create_object, shader_file, 0, 9831, 545, 10480);
		Sprite* frame18 = new Sprite(create_object, shader_file, 0, 10480, 551, 11132);
		Sprite* frame19 = new Sprite(create_object, shader_file, 0, 11132, 550, 11802);
		Sprite* frame20 = new Sprite(create_object, shader_file, 0, 11802, 551, 12454);
		Sprite* frame21 = new Sprite(create_object, shader_file, 0, 12454, 532, 13104);
		Sprite* frame22 = new Sprite(create_object, shader_file, 0, 13104, 551, 13761);
		Sprite* frame23 = new Sprite(create_object, shader_file, 0, 13761, 567, 14426);
		Sprite* frame24 = new Sprite(create_object, shader_file, 0, 14426, 564, 15069);
		Sprite* frame25 = new Sprite(create_object, shader_file, 0, 15069, 592, 15716);
		Sprite* frame26 = new Sprite(create_object, shader_file, 0, 15716, 606, 16333);
		clip->AddFrame(new Sprite(create_object, shader_file, 0, 0, 341, 615),       0.07f);
		clip->AddFrame(new Sprite(create_object, shader_file, 0, 615, 416, 1277),    0.07f);
		clip->AddFrame(new Sprite(create_object, shader_file, 0, 1277, 417, 1934),   0.07f);
		clip->AddFrame(new Sprite(create_object, shader_file, 0, 1934, 473, 2574),   0.07f);
		clip->AddFrame(new Sprite(create_object, shader_file, 0, 2574, 506, 3194),   0.07f);
		clip->AddFrame(new Sprite(create_object, shader_file, 0, 3194, 540, 3808),   0.07f);
		clip->AddFrame(new Sprite(create_object, shader_file, 0, 3808, 550, 4401),   0.07f);
		clip->AddFrame(new Sprite(create_object, shader_file, 0, 4401, 577, 4984),   0.07f);
		clip->AddFrame(new Sprite(create_object, shader_file, 0, 4984, 584, 5575),   0.07f);
		clip->AddFrame(new Sprite(create_object, shader_file, 0, 5575, 591, 6171),   0.07f);

		for (int i = 0; i < 3; ++i)
		{
			clip->AddFrame(frame11, 0.06f);
			clip->AddFrame(frame12, 0.06f);
			clip->AddFrame(frame13, 0.06f);
			clip->AddFrame(frame14, 0.06f);
			clip->AddFrame(frame11, 0.06f);
			clip->AddFrame(frame12, 0.06f);
			clip->AddFrame(frame13, 0.06f);
			clip->AddFrame(frame14, 0.06f);
			clip->AddFrame(frame15, 0.06f);
			clip->AddFrame(frame16, 0.06f);
			clip->AddFrame(frame17, 0.06f);				
			for (int j = 0; j < 5; ++j)
			{
				clip->AddFrame(frame18, 0.07f);// 21->27->33->39->45
				clip->AddFrame(frame19, 0.07f);
				clip->AddFrame(frame20, 0.07f);
				clip->AddFrame(frame21, 0.07f);
				clip->AddFrame(frame22, 0.07f);
				clip->AddFrame(frame23, 0.07f);
			}					   
			clip->AddFrame(frame24, 0.06f);
			clip->AddFrame(frame25, 0.06f);
			clip->AddFrame(frame26, 0.06f);
		}
		AddClip(clip);
	}

	wstring firing_seeds = L"Bosses/Cagney Carnation/Firing Seeds/Cagney_firing_seeds.png";
	{	// Firing seeds
		clip = new Clip(PlayMode::End);

		clip->AddFrame(new Sprite(firing_seeds, shader_file, 0, 0, 391, 610),     0.07f);
		clip->AddFrame(new Sprite(firing_seeds, shader_file, 0, 610, 500, 1197),  0.07f);
		clip->AddFrame(new Sprite(firing_seeds, shader_file, 0, 1197, 491, 1767), 0.07f);
		clip->AddFrame(new Sprite(firing_seeds, shader_file, 0, 1767, 453, 2363), 0.07f);
		clip->AddFrame(new Sprite(firing_seeds, shader_file, 0, 2363, 490, 2948), 0.07f);
		clip->AddFrame(new Sprite(firing_seeds, shader_file, 0, 2948, 504, 3491), 0.07f);
		clip->AddFrame(new Sprite(firing_seeds, shader_file, 0, 3491, 484, 4063), 0.07f);
		Sprite* frame8 = new Sprite(firing_seeds, shader_file, 0, 4063, 464, 4652);
		Sprite* frame9 = new Sprite(firing_seeds, shader_file, 0, 4652, 450, 5201);
		Sprite* frame10 = new Sprite(firing_seeds, shader_file, 0, 5201, 439, 5789);
		Sprite* frame11 = new Sprite(firing_seeds, shader_file, 0, 5789, 422, 6346);
		Sprite* frame12 = new Sprite(firing_seeds, shader_file, 0, 6346, 429, 6943);
		Sprite* frame13 = new Sprite(firing_seeds, shader_file, 0, 6943, 426, 7503);
		Sprite* frame14 = new Sprite(firing_seeds, shader_file, 0, 7503, 440, 8092);
		Sprite* frame15 = new Sprite(firing_seeds, shader_file, 0, 8092, 450, 8650);
		Sprite* frame16 = new Sprite(firing_seeds, shader_file, 0, 8650, 454, 9213);
		for (int i = 0; i < 9; ++i)
		{
			clip->AddFrame(frame8, 0.07f);
			clip->AddFrame(frame9, 0.07f);
			clip->AddFrame(frame10, 0.07f);
			clip->AddFrame(frame11, 0.07f);
			clip->AddFrame(frame12, 0.07f);
			clip->AddFrame(frame13, 0.07f);
			clip->AddFrame(frame14, 0.07f);
			clip->AddFrame(frame15, 0.07f);
			clip->AddFrame(frame16, 0.07f);
		}
		clip->AddFrame(new Sprite(firing_seeds, shader_file, 0, 9213, 477, 9745), 0.07f);
		clip->AddFrame(new Sprite(firing_seeds, shader_file, 0, 9745, 503, 10257), 0.07f);
		clip->AddFrame(new Sprite(firing_seeds, shader_file, 0, 10257, 476, 10799), 0.07f);
		clip->AddFrame(new Sprite(firing_seeds, shader_file, 0, 10799, 456, 11360), 0.07f);
		clip->AddFrame(new Sprite(firing_seeds, shader_file, 0, 11360, 482, 11959), 0.07f);
		clip->AddFrame(new Sprite(firing_seeds, shader_file, 0, 11959, 503, 12574), 0.07f);
		AddClip(clip);
	}

	wstring final_intro_01 = L"Bosses/Cagney Carnation/Final Form/Intro/Cagney_final_intro_01.png";
	wstring final_intro_02 = L"Bosses/Cagney Carnation/Final Form/Intro/Cagney_final_intro_02.png";
	{	// Final intro
		clip = new Clip(PlayMode::End);
		clip->AddFrame(new Sprite(final_intro_01, shader_file, 0, 0, 378, 606),     0.07f);
		clip->AddFrame(new Sprite(final_intro_01, shader_file, 0, 606, 440, 1208),  0.07f);
		clip->AddFrame(new Sprite(final_intro_01, shader_file, 0, 1208, 393, 1808), 0.07f);
		clip->AddFrame(new Sprite(final_intro_01, shader_file, 0, 1808, 424, 2407), 0.07f);
		clip->AddFrame(new Sprite(final_intro_01, shader_file, 0, 2407, 442, 3030), 0.07f);

		Sprite* frame6 = new Sprite(final_intro_01, shader_file, 0, 3030, 510, 3641);
		Sprite* frame7 = new Sprite(final_intro_01, shader_file, 0, 3641, 535, 4248);
		for (int i = 0; i < 6; ++i)
		{
			clip->AddFrame(frame6, 0.07f);//5, 7, 9, 11, 13, 15
			clip->AddFrame(frame7, 0.07f);
		}
		
		clip->AddFrame(new Sprite(final_intro_01, shader_file, 0, 4248, 511, 4853), 0.07f);//17
		clip->AddFrame(new Sprite(final_intro_01, shader_file, 0, 4853, 663, 5459), 0.07f);
		clip->AddFrame(new Sprite(final_intro_01, shader_file, 0, 5459, 661, 6052), 0.07f);
		clip->AddFrame(new Sprite(final_intro_01, shader_file, 0, 6052, 603, 6628), 0.07f);
		clip->AddFrame(new Sprite(final_intro_01, shader_file, 0, 6628, 564, 7199), 0.07f);
		clip->AddFrame(new Sprite(final_intro_01, shader_file, 0, 7199, 534, 7804), 0.07f);
		clip->AddFrame(new Sprite(final_intro_01, shader_file, 0, 7804, 517, 8416), 0.07f);//23
		clip->AddFrame(new Sprite(final_intro_02, shader_file, 0, 0, 494, 618), 0.07f);
		clip->AddFrame(new Sprite(final_intro_02, shader_file, 0, 618, 478, 1230), 0.07f);
		clip->AddFrame(new Sprite(final_intro_02, shader_file, 0, 1230, 362, 1847), 0.07f);

		Sprite* frame18 = new Sprite(final_intro_02, shader_file, 0, 1847, 331, 2481);
		Sprite* frame19 = new Sprite(final_intro_02, shader_file, 0, 2481, 314, 3115);
		Sprite* frame20 = new Sprite(final_intro_02, shader_file, 0, 3115, 326, 3743);
		Sprite* frame21 = new Sprite(final_intro_02, shader_file, 0, 3743, 327, 4373);
		for (int i = 0; i < 5; ++i)
		{
			clip->AddFrame(frame18, 0.07f); 
			clip->AddFrame(frame19, 0.07f);
			clip->AddFrame(frame20, 0.07f);
			clip->AddFrame(frame21, 0.07f);
		}
		
		clip->AddFrame(new Sprite(final_intro_02, shader_file, 0, 4373, 380, 5007), 0.07f);
		clip->AddFrame(new Sprite(final_intro_02, shader_file, 0, 5007, 372, 5642), 0.07f);
		clip->AddFrame(new Sprite(final_intro_02, shader_file, 0, 5642, 387, 6294), 0.07f);
		clip->AddFrame(new Sprite(final_intro_02, shader_file, 0, 6294, 382, 6928), 0.07f);
		clip->AddFrame(new Sprite(final_intro_02, shader_file, 0, 6928, 395, 7583), 0.07f);
		clip->AddFrame(new Sprite(final_intro_02, shader_file, 0, 7583, 406, 8242), 0.07f);
		clip->AddFrame(new Sprite(final_intro_02, shader_file, 0, 8242, 421, 8902), 0.07f);
		AddClip(clip);
	}

	wstring final_idle = L"Bosses/Cagney Carnation/Final Form/Cagney_final_idle.png";
	{	// Final idle
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(final_idle, shader_file, 0, 0, 434, 660), 0.07f);
		clip->AddFrame(new Sprite(final_idle, shader_file, 0, 660, 445, 1314), 0.07f);
		clip->AddFrame(new Sprite(final_idle, shader_file, 0, 1314, 449, 1961), 0.07f);
		clip->AddFrame(new Sprite(final_idle, shader_file, 0, 1961, 457, 2604), 0.07f);
		clip->AddFrame(new Sprite(final_idle, shader_file, 0, 2604, 459, 3246), 0.07f);
		clip->AddFrame(new Sprite(final_idle, shader_file, 0, 3246, 461, 3888), 0.07f);
		clip->AddFrame(new Sprite(final_idle, shader_file, 0, 3888, 462, 4529), 0.07f);
		clip->AddFrame(new Sprite(final_idle, shader_file, 0, 4529, 462, 5188), 0.07f);
		clip->AddFrame(new Sprite(final_idle, shader_file, 0, 5188, 463, 5864), 0.07f);
		clip->AddFrame(new Sprite(final_idle, shader_file, 0, 5864, 463, 6559), 0.07f);
		clip->AddFrame(new Sprite(final_idle, shader_file, 0, 6559, 491, 7265), 0.07f);
		clip->AddFrame(new Sprite(final_idle, shader_file, 0, 7265, 509, 7971), 0.07f);
		clip->AddFrame(new Sprite(final_idle, shader_file, 0, 7971, 514, 8675), 0.07f);
		clip->AddFrame(new Sprite(final_idle, shader_file, 0, 8675, 509, 9369), 0.07f);
		clip->AddFrame(new Sprite(final_idle, shader_file, 0, 9369, 497, 10049), 0.07f);
		clip->AddFrame(new Sprite(final_idle, shader_file, 0, 10049, 474, 10730), 0.07f);
		clip->AddFrame(new Sprite(final_idle, shader_file, 0, 10730, 467, 11405), 0.07f);
		clip->AddFrame(new Sprite(final_idle, shader_file, 0, 11405, 459, 12068), 0.07f);
		clip->AddFrame(new Sprite(final_idle, shader_file, 0, 12068, 459, 12731), 0.07f);
		AddClip(clip);
	}

	wstring firing_pollen = L"Bosses/Cagney Carnation/Final Form/Firing Pollen/Cagney_firing_pollen.png";
	{	// Firing pollen
		clip = new Clip(PlayMode::End);
		clip->AddFrame(new Sprite(firing_pollen, shader_file, 0, 0, 452, 653), 0.06f);
		clip->AddFrame(new Sprite(firing_pollen, shader_file, 0, 653, 441, 1302), 0.06f);
		clip->AddFrame(new Sprite(firing_pollen, shader_file, 0, 1302, 434, 1943), 0.06f);
		clip->AddFrame(new Sprite(firing_pollen, shader_file, 0, 1943, 438, 2561), 0.06f);
		clip->AddFrame(new Sprite(firing_pollen, shader_file, 0, 2561, 446, 3144), 0.06f);
		clip->AddFrame(new Sprite(firing_pollen, shader_file, 0, 3144, 488, 3748), 0.06f);
		clip->AddFrame(new Sprite(firing_pollen, shader_file, 0, 3748, 500, 4393), 0.06f);
		clip->AddFrame(new Sprite(firing_pollen, shader_file, 0, 4393, 504, 5038), 0.06f);
		clip->AddFrame(new Sprite(firing_pollen, shader_file, 0, 5038, 496, 5675), 0.06f);
		clip->AddFrame(new Sprite(firing_pollen, shader_file, 0, 5675, 505, 6266), 0.06f);
		clip->AddFrame(new Sprite(firing_pollen, shader_file, 0, 6266, 507, 6837), 0.06f);
		clip->AddFrame(new Sprite(firing_pollen, shader_file, 0, 6837, 531, 7393), 0.06f);
		clip->AddFrame(new Sprite(firing_pollen, shader_file, 0, 7393, 542, 7956), 0.06f);
		clip->AddFrame(new Sprite(firing_pollen, shader_file, 0, 7956, 572, 8542), 0.06f);
		clip->AddFrame(new Sprite(firing_pollen, shader_file, 0, 8542, 593, 9155), 0.06f);
		clip->AddFrame(new Sprite(firing_pollen, shader_file, 0, 9155, 621, 9680), 0.06f);
		clip->AddFrame(new Sprite(firing_pollen, shader_file, 0, 9680, 608, 10205), 0.06f);
		clip->AddFrame(new Sprite(firing_pollen, shader_file, 0, 10205, 533, 10761), 0.06f);
		clip->AddFrame(new Sprite(firing_pollen, shader_file, 0, 10761, 506, 11342), 0.06f);
		clip->AddFrame(new Sprite(firing_pollen, shader_file, 0, 11342, 434, 11944), 0.06f);
		clip->AddFrame(new Sprite(firing_pollen, shader_file, 0, 11944, 435, 12558), 0.06f);
		clip->AddFrame(new Sprite(firing_pollen, shader_file, 0, 12558, 465, 13189), 0.06f);
		AddClip(clip);
	}

	wstring death = L"Bosses/Cagney Carnation/Death/Cagney_death.png";
	{	// Death
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(death, shader_file, 0, 0, 453, 627), 0.07f);
		clip->AddFrame(new Sprite(death, shader_file, 0, 627, 456, 1253), 0.07f);
		clip->AddFrame(new Sprite(death, shader_file, 0, 1253, 458, 1879), 0.07f);
		clip->AddFrame(new Sprite(death, shader_file, 0, 1879, 462, 2498), 0.07f);
		clip->AddFrame(new Sprite(death, shader_file, 0, 2498, 466, 3132), 0.07f);
		clip->AddFrame(new Sprite(death, shader_file, 0, 3132, 476, 3753), 0.07f);
		clip->AddFrame(new Sprite(death, shader_file, 0, 3753, 479, 4378), 0.07f);
		clip->AddFrame(new Sprite(death, shader_file, 0, 4378, 490, 5000), 0.07f);
		clip->AddFrame(new Sprite(death, shader_file, 0, 5000, 475, 5628), 0.07f);
		clip->AddFrame(new Sprite(death, shader_file, 0, 5628, 468, 6250), 0.07f);
		clip->AddFrame(new Sprite(death, shader_file, 0, 6250, 491, 6874), 0.07f);
		clip->AddFrame(new Sprite(death, shader_file, 0, 6874, 461, 7498), 0.07f);
		AddClip(clip);
	}
}

void CagneyAnimation::Play(CAGNEY_ANIM state)
{
	Animation::Play(static_cast<UINT>(state));
}
