#pragma once
#include"NormalEnemy.h"
#include<list>
#include"EnemyTask.h"
#include<memory>
class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager() = default;
	bool Update();
	void Draw() ;
private :
	std::list<std::shared_ptr<Task>>_list;
};

