#pragma once
#include "Character/Attackable.h"
#include "Objects/EnemyObject.h"

class StaticCollisionList
{
	//friend unique_ptr<StaticCollisionList> std::make_unique<StaticCollisionList>();
	//friend unique_ptr<StaticCollisionList>::deleter_type;
public:
	static StaticCollisionList* Instance();
	static void Create();
	static void Delete();
	static void InsertAttackable(Attackable* attackable);
	static void InsertEnemyObject(EnemyObject* object);
	static void EraseAttackable(Attackable* attackable);
	static void EraseEnemyObject(EnemyObject* object);
	static void TakeDamage(int idx);
	static size_t AttackablesSize();
	static size_t EnemyObjectsSize();
	static Matrix& AttackableCollisionWorld(int idx);
	static Matrix& EnemyObjectCollisionWorld(int idx);
private:
	StaticCollisionList() = default;
	~StaticCollisionList() = default;

private:
	static StaticCollisionList* instance;
	static list<Attackable*> attackables;
	static list<EnemyObject*> enemy_objects;
};