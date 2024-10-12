#include "Enemy_B.h"
#include<DxLib.h>
BulletManager BEbullet;
CircleCollider BECol;

Enemy_B::Enemy_B()
{
	*_x = 100;
	*_y = -50;
	shotFlag = std::make_unique<bool>(false);
	*pattern = 2;
	*selection = 1;
}
Enemy_B::~Enemy_B()
{
	*handle = 0;
	DeleteGraph(*handle);
}
void Enemy_B::draw()
{
	*handle = LoadGraph("E:\\Aseprite\\chara0001.png");
	if (BECol.Player_EnemyB_update())
	{
		DrawGraph((float)*_x, (float)*_y, *handle, TRUE);
	}
	BEbullet.BulletDraw(this);
}