#pragma once
#include"AbstractEnemy.h"
#include<memory>
#include"BulletManager.h"
#include"CircleCollider.h"
class BulletManager;
class CircleCollider;

class Enemy_A:public AbstractEnemy
{
public:
	Enemy_A();
	virtual ~Enemy_A();

	void draw() override;


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

