#pragma once
#include"AbstractEnemy.h"
#include<memory>
#include"CircleCollider.h"
#include"BulletManager.h"
class CircleCollider;
class BulletManager;

class Enemy_B :public AbstractEnemy
{
public:
	Enemy_B();
	virtual ~Enemy_B();
	void draw()override;
	void SetFlag(bool flag)
	{
		*shotFlag = flag;
	}
	bool GetFlag()
	{
		return *shotFlag;
	}

private:
	std::unique_ptr<bool>shotFlag;
};

