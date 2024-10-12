#include "Enemy_A.h"

#include<DxLib.h>
CircleCollider Ecol;
BulletManager bulletmanagerEnemy_A;

Enemy_A::Enemy_A() {
	*_x = 400;
	*_y = -50;
	shotFlag = std::make_unique<bool>(false);
	*pattern = 1;
	*selection = 0;
	
}
Enemy_A::~Enemy_A()
{
	*handle = 0;
	DeleteGraph(*handle);

}


void Enemy_A::draw()
{
	*handle = LoadGraph("E:\\Aseprite\\bluearchiveyuuka.png");
	if (Ecol.Player_EnemyA_update()) {

		DrawGraph((float)*_x, (float)*_y, *handle, TRUE);
	}
	bulletmanagerEnemy_A.BulletDraw(this);
}

