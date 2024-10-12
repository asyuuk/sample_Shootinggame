#include "GameScene.h"
#include"Enemy_A.h"
#include"Enemy_B.h"
Player player;

Enemy_A EA;
Enemy_B  EB;

BackGround background;
GameScene::GameScene()
{
	
}

void GameScene::update()
{

	
}

void GameScene::draw()
{
	background.draw();

	EB.update();
	player.update();
	EA.update();
	player.draw();
	EA.draw();
	EB.draw();

	background.drawback();
}