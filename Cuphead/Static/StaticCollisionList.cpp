#include "stdafx.h"
#include "Static/StaticCollisionList.h"

StaticCollisionList* StaticCollisionList::instance = nullptr;
list<Attackable*> StaticCollisionList::attackables;
list<EnemyObject*> StaticCollisionList::enemy_objects;

StaticCollisionList * StaticCollisionList::Instance()
{
	return instance;
}

void StaticCollisionList::Create()
{
	instance = new StaticCollisionList();
}

void StaticCollisionList::Delete()
{
	delete instance;
}

void StaticCollisionList::InsertAttackable(Attackable* attackable)
{
	attackables.push_back(attackable);
}

void StaticCollisionList::InsertEnemyObject(EnemyObject* object)
{
	enemy_objects.push_back(object);
}

void StaticCollisionList::EraseAttackable(Attackable* attackable)
{
	list<Attackable*>::iterator iter = begin(attackables);
	for (iter; iter != end(attackables); ++iter)
	{
		if (*iter == attackable)
		{
			attackables.erase(iter);
			break;
		}
	}
}

void StaticCollisionList::EraseEnemyObject(EnemyObject* object)
{
	list<EnemyObject*>::iterator iter = begin(enemy_objects);
	for (iter; iter != end(enemy_objects); ++iter)
	{
		if (*iter == object)
		{
			enemy_objects.erase(iter);
			break;
		}
	}
}

void StaticCollisionList::TakeDamage(int idx)
{
	list<Attackable*>::iterator iter = begin(attackables);
	for (int i = 0; i < idx; i++)
		++iter;
	return (*iter)->TakenDamage();
}

size_t StaticCollisionList::AttackablesSize()
{
	return attackables.size();
}

size_t StaticCollisionList::EnemyObjectsSize()
{
	return enemy_objects.size();
}

Matrix & StaticCollisionList::AttackableCollisionWorld(int idx)
{
	list<Attackable*>::iterator iter = begin(attackables);
	for (int i = 0; i < idx; i++)
		++iter;
	return (*iter)->CollisionWorld();
}

Matrix & StaticCollisionList::EnemyObjectCollisionWorld(int idx)
{
	list<EnemyObject*>::iterator iter = begin(enemy_objects);
	for (int i = 0; i < idx; i++)
		++iter;
	return (*iter)->CollisionWorld();
}
