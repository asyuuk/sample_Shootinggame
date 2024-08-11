#pragma once

struct Circle {
	int x;
	int y;
	int r;
};

class ColliderClass
{
public:
	void Initialize();
	void Update();
	bool CircleCollision(int x,int y,int _H, int _W,int x2,int y2,int _H2,int _W2);
	Circle c;
	Circle c2;
};

