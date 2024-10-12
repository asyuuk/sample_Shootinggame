#include "MovePatternEnemys.h"
#include<DxLib.h>




MovePatternEnemys::MovePatternEnemys()
{
	
	SetFunction();
}


void MovePatternEnemys::move(AbstractEnemy* enemy)
{
	const unsigned int id = enemy->Getpattern();
	
	(this->*_movepattern[id])(enemy);
	enemy->SetX(enemy->GetX() + cos(enemy->Getangle1()) * enemy->Getspeed());
	enemy->SetY(enemy->GetY() + sin(enemy->Getangle1()) * enemy->Getspeed());
}

void MovePatternEnemys::SetFunction()
{
	_movepattern.push_back(&MovePatternEnemys::MovePattern00);
	_movepattern.push_back(&MovePatternEnemys::MovePattern01);
	_movepattern.push_back(&MovePatternEnemys::MovePattern02);
}
void  MovePatternEnemys::MovePattern00(AbstractEnemy* enemy)
{
	const int counter = enemy->Getcount();
	const int wait = 180;
	if (counter == 0)
	{
		enemy->Setangle1(DX_PI / 2);
		enemy->Setspeed(2);
	}
	if (60 < counter && counter <= 90)
	{
		enemy->Setspeed(enemy->Getspeed() - 0.1f);
	}
	if (90 + wait < counter && counter <= 90 + wait + 30)
	{
		enemy->Setspeed(enemy->Getspeed() + 0.1f);
	}
	
}

void MovePatternEnemys::MovePattern01(AbstractEnemy* enemy)
{
	const int counter = enemy->Getcount();
	if (0 == counter)
	{
		enemy->Setangle1(DX_PI * 3 / 4);
		enemy->Setspeed(2);
	}
	if (100 == counter)
	{
		enemy->Setspeed(0);
	}
	if (130 == counter)
	{
		enemy->Setspeed(-3);
	}
	
}
 
void MovePatternEnemys::MovePattern02(AbstractEnemy* enemy)
{
	const int counter = enemy->Getcount();
	if (0 == counter)
	{
		enemy->Setangle1(DX_PI * 1 / 4);
		enemy->Setspeed(4);
	}
}
void MovePatternEnemys::MovePattern03(AbstractEnemy* enemy)
{

}
void MovePatternEnemys::MovePattern04(AbstractEnemy* enemy)
{

}
void MovePatternEnemys::MovePattern05(AbstractEnemy* enemy)
{

}
void MovePatternEnemys::MovePattern06(AbstractEnemy* enemy)
{

}
void MovePatternEnemys::MovePattern07(AbstractEnemy* enemy)
{

}
void MovePatternEnemys::MovePattern08(AbstractEnemy* enemy)
{

}
 



