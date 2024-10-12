#pragma once

#include"AbstractEnemy.h"
#include<memory>

class AbstractEnemy;
class BulletManager
{
public:
	BulletManager();
	~BulletManager() = default;

	void set(int x) {
		*selection = x;
	}
	void shot(AbstractEnemy* enemy);

	void BulletSelect(AbstractEnemy* enemy);

	void BulletDraw(AbstractEnemy* enemy);

	


private:
	std::unique_ptr<int> selection;

	

};

enum
{
	Random,
	Circle,
	Shot_End
};
