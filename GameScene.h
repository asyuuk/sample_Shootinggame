#pragma once
#include"Player.h"
#include"AbstractEnemy.h"
#include"Enemy_A.h"
#include"CircleCollider.h"
#include"CircleShot.h"
#include"BackGround.h"
class GameScene
{
public:
	GameScene();
	virtual ~GameScene() = default;
	void update();
	void draw();
private:
	Enemy_A EA;

};

