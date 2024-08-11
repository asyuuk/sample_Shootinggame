#include "GameScene.h"
#include"NormalEnemy.h"
#include"Player.h"
#include<DxLib.h>
#include"Background.h"
#include"EnemyManager.h"
using namespace std;

GameScene::GameScene()
{
	_player = make_shared<Player>();
	_back = make_shared<Background>();
	_normal = make_shared<NormalEnemy>();
	_EnemyManager = make_shared<EnemyManager>();

	_player->Initialize();
	_normal->Initialize();
}

void GameScene::update()
{
	
	

	_player->Update();

	_EnemyManager->Update();
	
	
}

void GameScene::draw()const
{
	
	_back->SetDraw();
	_back->Draw();
	_player->Draw();
	_EnemyManager->Draw();
	_back->DrawEnd();
	
	
}