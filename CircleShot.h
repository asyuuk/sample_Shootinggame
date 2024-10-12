#pragma once
#include"Task_B.h"
#include"Enemy_A.h"
#include<memory>
class Enemy_A;
class CircleShot:public Task_B
{
public:
	CircleShot();
	virtual ~CircleShot() = default;
	bool Initialize(float _x, float _y)override;
	bool update(float _x, float _y)override;
	void Draw()const override;
	void SetX(float _x[]);
	void SetY(float _y[]);
	float GetX();
	float GetY();

private:
	std::unique_ptr<int>count;
	std::unique_ptr<float[]>angle;
	std::unique_ptr<float[]>angle2;
	std::unique_ptr<int[]>bullet;
	std::unique_ptr<float[]>x;
	std::unique_ptr<float[]>y;
	std::unique_ptr<int>max;
	std::unique_ptr<int>handle;
	std::unique_ptr<int>gamecount;
	std::unique_ptr<int>gamecount2;

};

