#include<iostream>
#include "ColliderClass.h"
#include<DxLib.h>


void ColliderClass::Initialize()
{
	
	
	
}
void ColliderClass::Update()
{
	
	
}
bool ColliderClass::CircleCollision(int x, int y, int _H, int _W, int x2, int y2, int _H2, int _W2)
{
	int _x, _y, _x2, _y2, ax, ay,arx,ary,r;
	_x2 = x2 - _W2;
	_y2 = y2 - _H2;
	_x = x - _W;
	_y = y - _H;



	c.x = _x ;
	c.y = _y ;
	c.r = 5;
	c2.x = _x2 ;
	c2.y = _y2 ;
	c2.r = 5;
	ax = c.x - c2.x;
	ay = c.y - c2.y;
	arx = ax * ax;
	ary = ay * ay;
	r = sqrt(arx + ary);
	DrawCircle(c.x,c.y, c.r, GetColor(255, 255, 255), TRUE);
	DrawCircle(c2.x, c2.y, c2.r, GetColor(0, 255, 0), TRUE);
	return (r<=c.r+c2.r) ? true : false;
}

