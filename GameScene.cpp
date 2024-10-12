#include "GameScene.h"

Player player;

Enemy_A enemyA;


BackGround background;
GameScene::GameScene()
{
	
}

void GameScene::update()
{

	player.update();
	EA.update();
	
}

void GameScene::draw()
{
	background.draw();


	player.update();
	EA.update();
	player.draw();
	EA.draw();
	

	background.drawback();
}