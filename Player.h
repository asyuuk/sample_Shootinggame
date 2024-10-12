#pragma once
#include"Task.h"
#include<memory>
#include"CircleCollider.h"
class CircleCollider;
class Player :public Task
{
public:
	Player();
	~Player();
	bool update()override;
	void draw() override;
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
	bool GetVisible(bool flag)
	{
		*visible = flag;
		return *visible;
	}

private:
	void move();
	std::unique_ptr<float>_x;
	std::unique_ptr<float>_y;
	std::unique_ptr<int>handle;
	std::unique_ptr<bool>visible;
	std::unique_ptr<float>speed;
	
};

