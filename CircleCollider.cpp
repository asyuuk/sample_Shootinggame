#include "CircleCollider.h"
#include"player.h"
#include"CircleShot.h"
#include"Enemy_A.h"
#include"RandamShot.h"
#include<DxLib.h>
#include<math.h>
Player _player;
Enemy_A  EAc;
Enemy_B EBc;
RandamShot randomcollider;
CircleShot circleshotcollider;

CircleCollider::CircleCollider()
{
	_x1 = std::make_unique<float>(0);
	_x1_1 = std::make_unique<float>(0);
	_y1 = std::make_unique<float>(0);
	_y1_2 = std::make_unique<float>(0);

}
bool CircleCollider::Player_EnemyA_update()
{
	_player.update();
	EAc.update();
	return Colliders(_player.GetX(), _player.GetY(),EAc.GetX(), EAc.GetY());
	
}

bool  CircleCollider::Player_EnemyB_update()
{
	_player.update();
	EBc.update();
	return  Colliders(_player.GetX(), _player.GetY(), EBc.GetX(), EBc.GetY());
}

bool CircleCollider::Player_Bullet_update()
{

	_player.update();
	circleshotcollider.Initialize(_player.GetX(), _player.GetY());

	
	return Colliders(_player.GetX(), _player.GetY(), circleshotcollider.GetX(), circleshotcollider.GetY());
}

bool CircleCollider::Player_Bullet_update_Random()
{
	
	randomcollider.Initialize(_player.GetX(), _player.GetY());

	return Colliders(_player.GetX(), _player.GetY(), randomcollider.GetX(), randomcollider.GetY());
}
bool CircleCollider::Colliders(float _x, float _y, float _x2, float _y2)
{


	*_x1 = _x;
	*_y1 = _y;
	*_x1_1 = _x2;
	*_y1_2 = _y2;
	
	DrawCircle(*_x1, *_y1, 10, GetColor(255, 255, 0));
	DrawCircle(*_x1_1, *_y1_2, 10, GetColor(0, 255, 255));
	float x, y, r,r2,rr;
	x = *_x1 - *_x1_1;

	y = *_y1 - *_y1_2;
	r = pow(x, 2) + pow(y, 2);
	r2 = 10;
	rr = 10 * 10;
	
	if (r < rr)
	{
		DrawCircle(*_x1, *_y1, 10, GetColor(200, 0, 200));
		DrawCircle(*_x1_1, *_y1_2, 10, GetColor(200, 0, 200));
		
		return false;
	}

	return true;
}