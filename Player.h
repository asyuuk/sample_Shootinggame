#pragma once
#include"EnemyTask.h"

class Player:public Task
{
public:
	Player();
	~Player()=default;

	void Initialize()override;
	bool Update()override;
	void Draw() override;
	void Move();
	void Shot();
	void GetGraphSizes();
	void CircleCollision();
	
	
	int moveX, moveY;
	bool flag=1;
private:

	int time;
	
	
};

