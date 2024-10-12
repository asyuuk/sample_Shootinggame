#pragma once
#include"Task_B.h"
#include<memory>


class InitTowardShot:public Task_B
{
public:
	InitTowardShot();
	virtual ~InitTowardShot() = default;
	virtual bool update(float _x, float _y)override;
	virtual void Draw()const override;

private:
	
};

