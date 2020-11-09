#pragma once

//HX 각 애니메이션 헤더파일 스마트 포인터 작업
// 통합 애니메이션 클래스
#pragma region ENUMCLASS
/*
enum class CHSTATE {
	Idle = 0,
	Duck,
	DuckIdle, DuckTurn, DuckShoot, DuckShootBoil,
	RunNormal = 20, 
	RunNormalTurnaround, RunShootingDiagonalUp,
	RunShootingDiagonalUpTurnaround, RunShootingStraight,
	RunShootingStraightTurnaround,
	AimUp = 30, 
	AimDown, AimStraight, AimDiagonalUp, AimDiagonalDown,
	Jump = 40, 
	JumpDust,
	ParryHand = 50,
	ParryHandPink, ParrySlapSpark, ParryAxe, ParryAttackSpark,
	DashAir = 60, 
	DashGround,
	ShootUp = 70, 
	ShootUpBoil, ShootDown, ShootDownBoil, ShootStraight, ShootStraightBoil,
	ShootDiagonalUp, ShootDiagonalUpBoil, ShootDiagonalDown, ShootDiagonalDownBoil,
	HitAir = 80, 
	HitGround,
	Death = 90,
	Ghost = 100, Revive,
	SAUpAir,
	SAUpGround, SADownAir, SADownGround, SAStraightAir, SAStraightGround,
	SADiagonalDownAir, SADiagonalDownGround, SADiagonalUpAir, SADiagonalUpGround, SASFX,
	Intro,
	IVTransformation, IVShadow,
	PowerUp,
	Scared,
	SBCuphead, SBSuperBeam, SBSuperIntroFX, SBSuperbeamFX,
	SPCuphead, SPBodyFloat, SPIntro, SPGhostIntro, SPGhostLariat
};
enum class FXSTATE {
	JumpDust,
	SASFX,
};
*/

enum class IDLE { Idle };
enum class DUCK { Duck, DuckIdle, DuckTurn, DuckShoot, DuckShootBoil };
enum class RUN {
	RunNormal, RunNormalTurnaround, RunShootingDiagonalUp,
	RunShootingDiagonalUpTurnaround, RunShootingStraight,
	RunShootingStraightTurnaround
};
enum class AIM { Up, Down, Straight, DiagonalUp, DiagonalDown };
enum class JUMP { Jump, Dust };
enum class PARRY { Hand, HandPink, SlapSpark, Axe, AttackSpark };
enum class DASH { DashAir, DashGround };
enum class SHOOT {
	Up, UpBoil, Down, DownBoil, Straight, StraightBoil,
	DiagonalUp, DiagonalUpBoil, DiagonalDown, DiagonalDownBoil
};
enum class HIT { HitAir, HitGround };
enum class SPECIALATTACK {
	UpAir, UpGround, DownAir, DownGround, StraightAir, StraightGround,
	DiagonalDownAir, DiagonalDownGround, DiagonalUpAir, DiagonalUpGround, SFX
};
enum class DEATH { Death };
enum class GHOST { Ghost, Revive };
enum class INTRO { Intro };
enum class INVINCIBILITY { Transformation, Shadow };
enum class POWERUP { PowerUp };
enum class SCARED { Scared };
enum class SUPERBEAM { Cuphead, SuperBeam, SuperIntroFX, SuperbeamFX };
enum class STARPLATINUM { Cuphead, BodyFloat, Intro, GhostIntro, GhostLariat };
#pragma endregion

class CupheadAnimation
{
public:
	CupheadAnimation();
	~CupheadAnimation();

	void Update(Matrix& V, Matrix& P);
	void Render();

	void Position(float x, float y);
	void Position(Vector2& vec);
	Vector2 Position();
	void Scale(float x, float y);
	void Scale(Vector2& vec);
	Vector2 Scale();
	void Rotation(float x, float y, float z);
	void Rotation(Vector3& vec);
	Vector3 Rotation();
	void RotationDegree(float x, float y, float z);
	void RotationDegree(Vector3& vec);
	Vector3 RotationDegree();

	void PlayAim(AIM state);
	void PlayDash(DASH state);
	void PlayDeath(DEATH state);
	void PlayDuck(DUCK state);
	void PlayIdle(IDLE state);
	void PlayJump(JUMP state);
	void PlayRun(RUN state);
	void PlayShoot(SHOOT state);

	Animation* CurrentAnim();
	float ForwardVector();

private:
	wstring shaderFile;

	Vector2 position;
	Vector2 scale;
	Vector3 rotation;

	unique_ptr<class AimAnim> aimAnim;
	unique_ptr<class DashAnim> dashAnim;
	unique_ptr<class DeathAnim> deathAnim;
	unique_ptr<class DuckAnim> duckAnim;
	unique_ptr<class IdleAnim> idleAnim;
	unique_ptr<class JumpAnim> jumpAnim;
	unique_ptr<class RunAnim> runAnim;
	unique_ptr<class ShootAnim> shootAnim;

	Animation* currentAnimation;
};
