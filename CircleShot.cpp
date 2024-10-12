#include "CircleShot.h"
#include<DxLib.h>
Enemy_A Flag;
CircleShot::CircleShot()
{
	count = std::make_unique<int>(30);
	angle = std::make_unique<float[]>(2560);
	angle2 = std::make_unique<float[]>(2560);
	bullet = std::make_unique<int[]>(2560);
	x = std::make_unique<float[]>(2560);
	y = std::make_unique<float[]>(2560);
	max = std::make_unique<int>(30);
	handle = std::make_unique<int>(0);
	gamecount2 = std::make_unique<int>(20);
	gamecount = std::make_unique<int>(0);
	
	for (int i = 0; i < 2560; i++)
	{
		x[i] = -10;
		y[i] = -10;
	}
}

void CircleShot::SetX(float _x[])
{
	for (int i = 0; i < 300; i++)
	{
		x[i] = _x[i];
	}
}
void CircleShot::SetY(float _y[])
{
	for (int i = 0; i < 300; i++)
	{

		y[i] = _y[i];
	}
}
float CircleShot::GetY(){
	for (int i = 0; i < 300; i++)
	{
		return y[i];
	}
}
float CircleShot::GetX()
{
	for(int i=0;i<300;i++)
	return x[i];
}

bool CircleShot::Initialize(float _x, float _y)
{
	if (Flag.GetFlag() == false) {

		*max = 40;
		for (int i = 0; i < *count; i++)
		{
			angle[i] = (18 * i) * DX_PI / 180;
			angle[i + *count] = (18 * i) * DX_PI / 180;
			angle2[i] = ((18 * i) + 4) * DX_PI / 180;
			angle2[i + *count] = ((18 * i) - 4) * DX_PI / 180;

		}
		for (int j = 0; j < 300; j++)
		{
			x[j] = _x;
			y[j] = _y;
		}
		Flag.SetFlag(true);
	}
	
	return true;
}

bool CircleShot::update(float _x, float _y)
{
	

		for (int i = 0; i < *max; i++)
		{
			if (x[i]<80 && x[i]>-80 && y[i]<80 && y[i]>-80)
			{
				x[i] += cos(angle[i % 40]) * 2;
				y[i] += sin(angle[i % 40]) * 2;
			}
			else
			{
				x[i] += cos(angle2[i % 40]) * 2;
				y[i] += sin(angle2[i % 40]) * 2;
			}
		}
		if (*gamecount == *gamecount2)
		{
			if (*max < 280) {
				*max += 40;
				*gamecount2 += 20;
				
			}


		
		
	}

		*gamecount+=1;
	return true;

}

void  CircleShot::Draw()const
{
	*handle = LoadGraph("E:\\Aseprite\\bullet00003.png");
	for (int i = 0; i < *max; i++) {
		DrawGraph(x[i], y[i], *handle, true);

	}
}