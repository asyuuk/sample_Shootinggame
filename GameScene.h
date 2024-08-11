#pragma once

#include"AbstructScene.h"
#include<memory>
#include"Player.h"
#include"NormalEnemy.h"
#include"Background.h"
#include"EnemyManager.h"
#include"ColliderClass.h"


class GameScene:public AbstructScene
{
public:
	GameScene();
	virtual ~GameScene() = default;

	void update() override;
	void draw() const override;
private:
	std::shared_ptr<Player>_player;
	std::shared_ptr<NormalEnemy> _normal;
	std::shared_ptr<Background>_back;
	std::shared_ptr<EnemyManager> _EnemyManager;
	std::shared_ptr<ColliderClass>_Collider;
	

};

