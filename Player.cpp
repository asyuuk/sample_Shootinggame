#include "Player.h"
#include<memory>
#include<DxLib.h>
#include<math.h>
#include"NormalEnemy.h"
#include"Define.h"
#include"ColliderClass.h"
ColliderClass Circle;
NormalEnemy Ne;

Player::Player()
{
	
}


void Player::Initialize()
{
	
	flag = 1;
	moveX = Playerx;
	moveY = Playery;
	
	Ne.time = GetNowCount();
	for (int i = 0; i < PlayerShot; i++)
	{
		_bx[i] = Playerx;
		_by[i] = Playery;
		ShotValid[i] = 0;
	}
	
	GetGraphSizes();

	
}

bool Player::Update()
{
	Move();
	Shot();
	Ne.RM();
	CircleCollision();

	count++;
	
	return true;

}

void  Player::Draw() 
{
	if (framecount == 5)
	{
		animationFrame++;
		framecount = 0;
	}
	if (animationFrame == 2)
	{
		animationFrame = 0;
	}
	//プレイヤーロ―ド
	
	//弾ロード
	
	CircleCollision();
	
	
	if (flag == 1)
	{
		framecount++;
		DrawGraph(_x, _y, Graphs[animationFrame], TRUE);
	}
	Graphs_s.push_back(Graphs[animationFrame]);
	
	//弾描写
	for (int i = 0; i < PlayerShot; i++)
	{
		if (flag == 1)
		{
			if (ShotValid[i] == 1)
			{
				DrawGraph(_bx[i], _by[i], BulletGraph, TRUE);
				DrawGraph(_bx[i] + 20, _by[i], BulletGraph, TRUE);
			
			}
			

		}
		
	}
	Graphs_s.push_back(BulletGraph);
	
	
}

void  Player::Move()
{
	
		if ( CheckHitKey( KEY_INPUT_W ) )
		{
			moveY -= 2;
		}
		if ( CheckHitKey( KEY_INPUT_S ) )
		{
			moveY += 2;
		}
		if ( CheckHitKey( KEY_INPUT_D ) )
		{
			moveX += 2;
		}
		if ( CheckHitKey( KEY_INPUT_A ) )
		{
			moveX -= 2;
		}
		if (moveX && moveY)
		{

		}
		_x = moveX;
		_y = moveY;
		
		if (_x < 5)
		{
			_x = 5;
		}
		else if (_x > PlayerX)
		{
			_x = PlayerX;
		}
		
		if (_y < 10)
		{
			_y = 10;
		}
		else if (_y > PlayerY)
		{
			_y = PlayerY;
		}
		
}




void Player::Shot()
{
	


	if (CheckHitKey(KEY_INPUT_SPACE)) {

		for (int i = 0; i < PlayerShot; i++)
		{
			if (ShotValid[i] == 1)//ショットの処理
			_by[i] -= 8;
		
			if (_by[i] < -180)
			{
				ShotValid[i] = 0;
			}
			
			
		}
		
	}
	else
	{
		for (int i = 0; i < PlayerShot; i++)
		{
			ShotValid[i] = 0;
		}
	}
	if (CheckHitKey(KEY_INPUT_SPACE) && count % 2 == 0) {
		
		for (int i = 0; i < PlayerShot; i++)
		{
			if (ShotValid[i] == 0)
			{
				_bx[i] = _x;
				_by[i] = _y;
				ShotValid[i] = 1;
				break;
			}

		}
		
	}


}

void Player::GetGraphSizes()
{
	LoadDivGraph("E:\\Aseprite\\sentouki.png", 2, 2, 1, 32, 32, Graphs);
	BulletGraph = LoadGraph("E:\\Aseprite\\bullet00003.png");
	GetGraphSize(Graphs[0], &_W, &_H);
	
	GetGraphSize(BulletGraph, &_BW, &_BH);

}



void Player::CircleCollision()
{
	
	for (int i = 0; i < 20; i++)
	{
		if (Ne.flag[i] == 1) {
			if (Circle.CircleCollision(_x+45, _y+40, _H, _W, Ne.x[i]-10, Ne.y[i]-40, Ne._H, Ne._W))
			{
				flag = 0;
			}
		}

	}

	for (int i = 0; i < 256; i++)
	{
		for (int j = 0; j < 40; j++) {
			if (ShotValid[i] == 1)
			{
				if (Circle.CircleCollision(_bx[i]+20, _by[i], _BH, _BW, Ne.x[j]-10, Ne.y[j]-40, Ne._H, Ne._W))
				{
					ShotValid[i] = 0;
				}
			}
		}
		
	}

	

}