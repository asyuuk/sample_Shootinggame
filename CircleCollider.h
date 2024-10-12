#pragma once

#include<memory>
#include"player.h"

class Player;


class CircleCollider
{
public:
	CircleCollider();
	virtual ~CircleCollider() = default;

	
	bool Colliders(float _x,float _y,float _x2,float _y2);
	bool BulletCollider();
	bool Player_EnemyA_update();
	bool Player_Bullet_update();
	bool Player_EnemyB_update();

	bool Player_Bullet_update_Random();

	

private:
	std::unique_ptr<float>_x1;
	std::unique_ptr<float>_y1;
	std::unique_ptr<float>_x1_1;
	std::unique_ptr<float>_y1_2;

	
};

