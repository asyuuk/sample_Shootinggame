#include "Player.h"
#include<DxLib.h>



CircleCollider PCol;
Player::Player()
{
	_x = std::make_unique<float>();
	_y = std::make_unique<float>();
	handle = std::make_unique<int>();
	speed = std::make_unique<float>(2);
	*_x = 150;
	*_y = 380;
	*handle = 0;
	
}
Player::~Player()
{
	DeleteGraph(*handle);
}

bool Player::update()
{
	move();

	return true;
}

void  Player::draw()
{

	*handle = LoadGraph("E:\\Aseprite\\chara0002.png");
	if (PCol.Player_EnemyA_update()||PCol.Player_EnemyB_update()) {
		DrawGraph(*_x, *_y, *handle, TRUE);
	}
	
}

void Player::move()
{
	if (CheckHitKey(KEY_INPUT_W))
	{
		*_y -= *speed;
	}
	if (CheckHitKey(KEY_INPUT_S))
	{
		*_y += *speed;
	}
	if (CheckHitKey(KEY_INPUT_D))
	{
		*_x += *speed;
	}
	if (CheckHitKey(KEY_INPUT_A))
	{
		*_x -= *speed;
	}


}