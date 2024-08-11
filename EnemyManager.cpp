#include "EnemyManager.h"
#include"NormalEnemy.h"
EnemyManager::EnemyManager()
{
	_list.emplace_back(std::make_shared<NormalEnemy>());
	for (auto it =_list.begin(); it != _list.end(); ++it)
	{

		(*it)->Initialize();
	}
}

bool EnemyManager::Update()
{
	for (auto it = _list.begin(); it != _list.end();)
	{
		if ((*it)->Update() == false)
		{
			it = _list.erase(it);
		}
		else
		{
			it++;
		}
	}
	return true;
}

void EnemyManager::Draw()
{
	for (auto enemy = _list.begin(); enemy != _list.end(); ++enemy)
	{
		(*enemy)->Draw();
		
	}
}