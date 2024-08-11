#include "NormalEnemy.h"
#include"Define.h"
#include"Player.h"
#include<math.h>
#include"ColliderClass.h"
Player  _Player;
ColliderClass colenemy;


#define shot 20

NormalEnemy::NormalEnemy()
{
	
}




void NormalEnemy::Initialize()
{
	_Player.moveX = Playerx;
	_Player.moveY = Playery;
	for (int i = 0; i < 40; i++)
	{
		HP[i] = 2;
		flag[i] = 0;
		x[i] = -10;
		y[i] = -10;
	}
	for (int i = 0; i < shot; i++)
	{
		ShotValid[i] = 0;
	}
	
	for (int i = 0; i < 256; i++)
	{
		_Player._bx[i] = Playerx;
		_Player._by[i] = Playery;
		_Player.ShotValid[i] = 0;
	}
	
	framecount = 0;
	
	time = GetNowCount();
	for (int i = 0; i < 40; i++)
	{
		flag[i] = 0;
	}
	_Player.GetGraphSizes();
	GetGraphSizes();
}

void NormalEnemy::RM()
{
	Time = GetNowCount() - time;
	MovePattern();
	MovePattern2();
	MovePattern3();
	MovePattern4();

	Shot();
	count++;
	
}
void NormalEnemy::PlayerMoveShot()
{
	if (CheckHitKey(KEY_INPUT_W))
	{
		_Player.moveY -= 2;
	}
	if (CheckHitKey(KEY_INPUT_S))
	{
		_Player.moveY += 2;
	}
	if (CheckHitKey(KEY_INPUT_D))
	{
		_Player.moveX += 2;
	}
	if (CheckHitKey(KEY_INPUT_A))
	{
		_Player.moveX -= 2;
	}
	if (_Player.moveX && _Player.moveY)
	{

	}
	_Player._x = _Player.moveX;
	_Player._y = _Player.moveY;

	if (_x < 5)
	{
		_Player._x = 5;
	}
	else if (_Player._x > PlayerX)
	{
		_Player._x = PlayerX;
	}

	if (_Player._y < 10)
	{
		_Player._y = 10;
	}
	else if (_Player._y > PlayerY)
	{
		_Player._y = PlayerY;
	}

	//shot
	if (CheckHitKey(KEY_INPUT_SPACE)) {

		for (int i = 0; i < 256; i++)
		{
			if (_Player.ShotValid[i] == 1)//ƒVƒ‡ƒbƒg‚Ìˆ—
				_Player._by[i] -= 8;

			if (_Player._by[i] < -180)
			{
				_Player.ShotValid[i] = 0;
			}


		}

	}
	else
	{
		for (int i = 0; i < 256; i++)
		{
			_Player.ShotValid[i] = 0;
		}
	}
	if (CheckHitKey(KEY_INPUT_SPACE) && _Player.count % 9 == 0) {

		for (int i = 0; i < 256; i++)
		{
			if (_Player.ShotValid[i] == 0)
			{
				_Player._bx[i] = _Player._x;
				_Player._by[i] = _Player._y;
				_Player.ShotValid[i] = 1;
				break;
			}

		}

	}
	_Player.count++;
}
bool NormalEnemy::Update()
{
	
	//enemy movepattern
	Time = GetNowCount() - time;
	MovePattern();
	MovePattern2();
	MovePattern3();
	MovePattern4();
	//PlayerMoveShot();
	_Player.Move();
	_Player.Shot();

	CircleCollision();
	
	
	count++;
	

	return true;
}

void NormalEnemy::Draw()
{
	Time = GetNowCount() - time;

	if (framecount == 6)
	{
		animationFrame++;
		framecount = 0;
	}
	if (animationFrame == 2)
	{
		animationFrame = 0;
	}
	

	CircleCollision();

	framecount++;
	for (int i = 0; i < 40; i++) {
		if (HP[i] <= 0)
		{
			flag[i] = 0;
		}
		if (flag[i] == 1) {

			DrawGraph(x[i], y[i], Graphs[animationFrame], TRUE);


		}
		
			
	}

	
	


	Graphs_s.push_back(Graphs[animationFrame]);

	BulletGraph = LoadGraph("E:\\Aseprite\\bullet00007.png");
	for (int j = 0; j < 20; j++) {
		if (flag[j] == 1)
		{
			for (int i = 0; i < shot; i++)
			{
				if (ShotValid[i] == 1)
				{
					DrawGraph(_bx[i], _by[i], BulletGraph, TRUE);
				}

			}
		}

	}

	Graphs_s.push_back(BulletGraph);



}


void NormalEnemy::Move()
{
	
}

void NormalEnemy::MovePattern()
{
	if (Time > Count)
	{
		for (int i = 0; i < 10; i++)
		{
			if (flag[i] == 1)
			{
				x[i] -= 1;
				y[i] += 3;
				if (Time > 3000)
				{
					x[i] += 1;
					y[i] += 0;
				}
			}
			if (y[i] > 500)
			{
				flag[i] = -1;
				
			}
		}
	}
	if (Time > Count && count % 10 == 0)
	{
		for (int i = 0; i < 10; i++)
		{
			if (flag[i] == 0)
			{
				x[i] = 400;
				y[i] = -10;
				flag[i] = 1;
				break;
			}
		}
	}
		
	
	
}

void NormalEnemy::MovePattern2()
{
	if (Time > Count+100)
	{
		for (int i = 10; i < 20; i++)
		{
			if (flag[i] == 1)
			{
				x[i] += 1;
				y[i] += 3;
				
			}
			if (y[i] > 500)
			{
				flag[i] = -1;
				
			}
		}
	}
	if (Time > Count+100 && count % 10 == 0)
	{
		for (int i = 10; i < 20; i++)
		{
			if (flag[i] == 0)
			{
				x[i] = -30;
				y[i] = 0;
				flag[i] = 1;
				break;
			}
		}
	}

}

void NormalEnemy::MovePattern3()
{
	moving = 100;
	if (Time > Count + 1000)
	{
		for (int i = 20; i < 30; i++)
		{
			if (flag[i] == 1)
			{
				x[i] += cos(moving * (PI / 180)) * 4;
				y[i] += sin(moving * (PI / 180)) * 4;
				
			}
			if (y[i] > 500)
			{
				flag[i] = -1;
				
			}
		}
	}
	if (Time > Count + 1000 && count % 20 == 0)
	{
		for (int i = 20; i < 30; i++)
		{
			if (flag[i] == 0)
			{
				x[i] = 150;
				y[i] = 0;
				flag[i] = 1;
				break;
			}
		}
	}
}
void NormalEnemy::MovePattern4()
{
	moving = 68;
	if (Time > Count + 1000)
	{
		for (int i = 30; i < 40; i++)
		{
			if (flag[i] == 1)
			{
				x[i] += cos(moving * (PI / 180)) * 4;
				y[i] += sin(moving * (PI / 180)) * 4;

			}
			if (y[i] > 500)
			{
				flag[i] = -1;
				
			}
		}
	}
	if (Time > Count + 1000 && count % 20 == 0)
	{
		for (int i = 30; i < 40; i++)
		{
			if (flag[i] == 0)
			{
				x[i] = 200;
				y[i] = 0;
				flag[i] = 1;
				break;
			}
		}
	}
}
void NormalEnemy::Shot()
{
	
	if (Time > Count+2000) 
	{
		for (int j = 0; j < 40; j++)
		{
			for (int i = 0; i < shot; i++)
			{
				if (ShotValid[i] == 0)
				{
 					_bx[i] = x[j];
					_by[i] = y[j];
					
					ShotValid[i] = 1;
					break;
				}
			}



			if (Time > Count + 100 && count % 10 == 0) {
				for (int i = 0; i < shot; i++)
				{
					if(ShotValid[i]==1)
					{
						
						_by[i] += 3;
					}
					
					if (_by[i] > 20000)
					{
						ShotValid[i] = 0;
					}
				}
			}

		}

	}
	
	
}



void NormalEnemy::GetGraphSizes()
{
	LoadDivGraph("E:\\Aseprite\\B.png", 2, 2, 1, 5, 6, Graphs);
	GetGraphSize(Graphs[0], &_W, &_H);
}



void NormalEnemy::CircleCollision()
{
	//move
	
	
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < 256; j++)
			{

				if (_Player.ShotValid[j] == 1) {
					if (colenemy.CircleCollision(x[i], y[i], _H, _W, _Player._bx[j] + 20, _Player._by[j] + 30, _Player._BH, _Player._BW))
					{
						HP[i]--;
					}
					if (colenemy.CircleCollision(x[i], y[i], _H, _W, _Player._bx[j] + 40, _Player._by[j] + 30, _Player._BH, _Player._BW))
					{
						HP[i]--;
					}
					if (HP[i] <= 0)
					{
						flag[i] = 0;
					}

				}

			}


		}
	}
	
}

bool NormalEnemy::Inside()
{
	for (int i = 0; i < 40; i++)
	{
		if (flag[i] == -1)
		{
			return false;
			
		}
		
	}
	return true;
}