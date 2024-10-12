#pragma once
#include"Task.h"
#include<memory>

#include"BulletManager.h"

class BulletManager;



class AbstractEnemy:public Task
{
public:
	AbstractEnemy();
	virtual ~AbstractEnemy() = default;
	bool update()override;


	float& GetX()
	{
		return *_x;
	}
	 float& GetY()
	{
		return *_y;
	}
	void SetX(float x)
	{
		*_x = x;
	}

	 void SetY(float y)
	{
		*_y = y;
	}
	 bool Getvisible(bool flag)
	{
		*visible = flag;
		return *visible;
	}
	 int Getcount()
	{
		return *count;
	}

	 void Setcount(int _count)
	{
		*count = _count;
	}

	 float Getangle1()
	{
		return *_angle1;
	}
	 void Setangle1(float angle1)
	{
		*_angle1 = angle1;
	}
	 float Getangle2()
	{
		return *_angle2;
	}
	 void Setangle2(float angle2)
	{
		*_angle2 = angle2;
	}
	float Getspeed()
	{
		return *_speed;
	}
	const void Setspeed(float  speed)
	{
		*_speed = speed;
	}
	int Getpattern() {
		return *pattern;
	}
	 void Setpattern(int _pattern)
	{
		*pattern = _pattern;
	}
	 void SetCounterB(int  _counterb)
	 {
		 *counterbullet = _counterb;
	 }
	 int GetCounterB()
	 {
		 return *counterbullet;
	 }
	 int GetSelection()
	 {
		 return *selection;
	 }
	 void SetSelection(int _selection)
	 {
		 *selection = _selection;
	 }
protected:
	std::unique_ptr<float>_x;
	std::unique_ptr<float>_y;
	std::unique_ptr<float>_angle1;
	std::unique_ptr<float>_angle2;
	std::unique_ptr<float>_speed;
	std::unique_ptr<int>handle;
	std::unique_ptr<bool>visible;
	std::unique_ptr<int>count;
	std::unique_ptr<int>pattern;
	std::unique_ptr<int>counterbullet;
	std::unique_ptr<int>bulletpattern;
	std::unique_ptr<int>selection;
	void move();
	
};

