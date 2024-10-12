#include "RandamShot.h"
#include<DxLib.h>

Enemy_A enemyA_Randombullet;

RandamShot::RandamShot()
{

	count = std::make_unique<int>(30);
	angle = std::make_unique<float[]>(2560);
	angle2 = std::make_unique<float[]>(2560);
	bullet = std::make_unique<int[]>(2560);
	x = std::make_unique<int[]>(2560);
	y = std::make_unique<int[]>(2560);
	max = std::make_unique<int>(350);
	handle = std::make_unique<int>(0);
	gamecount2 = std::make_unique<int>(20);
	gamecount = std::make_unique<int>(0);
	var = std::make_unique<int[]>(2560);
	for (int i = 0; i < 2560; i++)
	{
		x[i] = -10;
		y[i] = -10;
	}
}
RandamShot::~RandamShot()
{
	DeleteGraph(*handle);
}

bool RandamShot::Initialize(float _x, float _y)
{
	if (enemyA_Randombullet.GetFlag()==false) {
		
		for (int i = 0; i < 2000; i++)
		{
			x[i] = _x;
			y[i] = _y;
		}
		for (int i = 0; i < 2000; i++)
		{
			angle[i] = ((rand() % 360) * (DX_PI / 180));
		}
		for (int i = 0; i < 2000; i++)
		{
			var[i] = (rand() % 5) +6;
		}
		enemyA_Randombullet.SetFlag(true);
	}
	

	return true;
}

bool RandamShot::update(float _x,float _y)
{
	if (enemyA_Randombullet.GetFlag() == true) {
		for (int i = 0; i < *max; i++)
		{

			x[i] += (cos(angle[i]) * var[i])/3;
			y[i] += (sin(angle[i]) * var[i])/3;
		}
		if (*gamecount == *gamecount2)
		{
			if (*max < 500)
			{
				*max += 40;
				*gamecount2 += 100;

			}
		}
	}
	
	*gamecount += 1;
	return true;
}

void  RandamShot::Draw()const
{
	*handle = LoadGraph("E:\\Aseprite\\bullet00003.png");
	for (int i = 0; i < *max; i++)
	{
		DrawGraph(x[i], y[i], *handle, true);
	}

}

float RandamShot::GetX()
{
	for (int i = 0; i < 300; i++)
	{
		return x[i];
	}
}

float RandamShot::GetY()
{
	for (int i = 0; i < 300; i++)
	{
		return y[i];
	}
}

void RandamShot::SetX(float _x[])
{
	for (int i = 0; i < 300; i++)
	{
		x[i] = _x[i];
	}
}

void RandamShot::SetY(float _y[])
{
	for (int i = 0; i < 300; i++)
	{
		y[i] = _y[i];
	}
}