#pragma once
#include<memory>
#include<vector>
#include"AbstractEnemy.h"

class AbstractEnemy;
class MovePatternEnemys
{
public:

	MovePatternEnemys();
	~MovePatternEnemys() = default;

	

	void update();
	void move(AbstractEnemy* enemy);
private:
	typedef void (MovePatternEnemys::* FUNC)(AbstractEnemy* enemy);
	std::vector<FUNC>_movepattern;

	void SetFunction();

	void MovePattern00(AbstractEnemy* enemy);
	void MovePattern01(AbstractEnemy* enemy);
	void MovePattern02(AbstractEnemy* enemy);
	void MovePattern03(AbstractEnemy* enemy);
	void MovePattern04(AbstractEnemy* enemy);
	void MovePattern05(AbstractEnemy* enemy);
	void MovePattern06(AbstractEnemy* enemy);
	void MovePattern07(AbstractEnemy* enemy);
	void MovePattern08(AbstractEnemy* enemy);
};

