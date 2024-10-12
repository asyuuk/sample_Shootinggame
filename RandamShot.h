#pragma once
#include"Task_B.h"
#include<memory>
#include"Enemy_A.h"
class Enemy_A;
class RandamShot:public Task_B
{
public:
	RandamShot();
	virtual ~RandamShot();
	bool Initialize(float _x, float _y)override;
	virtual bool update(float _x, float _y)override;
	virtual void Draw()const override;
	void SetX(float x[]);
	void SetY(float y[]);
	float GetX();
	float GetY();
	
private:
	std::unique_ptr<int>count;
	std::unique_ptr<float[]>angle;
	std::unique_ptr<float[]>angle2;
	std::unique_ptr<int[]>bullet;
	std::unique_ptr<int[]>var;
	std::unique_ptr<int>max;
	std::unique_ptr<int>handle;
	std::unique_ptr<int>gamecount;
	std::unique_ptr<int>gamecount2;
	std::unique_ptr<int[]>x;
	std::unique_ptr<int[]>y;

};

