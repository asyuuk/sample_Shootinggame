#pragma once
#include"EnemyTask.h"
#include<DxLib.h>


class NormalEnemy :public Task 
{
public:
	NormalEnemy();
	~NormalEnemy()=default;
	
	void Initialize() override;
	bool  Update() override;
	void Draw()  override;
	void Move();
	void Shot();
	void GetGraphSizes();
	void CircleCollision();

	
	bool Inside();
	void RM();
	int time;
	int flag[256];
protected:
	void MovePattern();
	void MovePattern2();
	void MovePattern3();
	void MovePattern4();
	void PlayerMoveShot();

	int TimeCount();
	
	int flag2[256];
	int moving = 0;
	int NormalEnemy_W;
	int NormalEnemy_H;
	int movex, movey;

	int Enemy_x, Enemy_y, Player_x, Player_y, bullet, bulletx, bullety;
	
	int Count = 1000;
};

