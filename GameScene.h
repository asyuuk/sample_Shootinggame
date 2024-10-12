#pragma once
#include"Player.h"

#include"Enemy_A.h"
#include"Enemy_B.h"
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
	

};

