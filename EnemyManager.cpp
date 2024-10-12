#include "EnemyManager.h"
#include"Enemy_A.h"
#include<Dxlib.h>
using namespace std;

EnemyManager::EnemyManager()
{
	_list.emplace_back(make_shared<Enemy_A>());
	

}

bool EnemyManager::update()
{
	for (auto it = _list.begin(); it != _list.end();)
	{
		if ((*it)->update() == false)
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

void  EnemyManager::draw()
{
	for (const auto enemy : _list)
	{
		enemy->draw();
	}
}