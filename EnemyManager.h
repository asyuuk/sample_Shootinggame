#pragma once
#include<memory>
#include<list>
#include"Task.h"
#include"BulletManager.h"
#include"AbstractEnemy.h"

class AbstractEnemy;

class EnemyManager:public Task
{
public:
	EnemyManager();
	virtual ~EnemyManager() = default;
	bool update() override;
	void draw() override;
private:
	std::list<std::shared_ptr<AbstractEnemy>>_list;
	std::list<std::shared_ptr<BulletManager>>_listB;

};

