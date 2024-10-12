#include "BulletManager.h"
#include"RandamShot.h"
#include"CircleShot.h"
#include"MovePatternEnemys.h"

MovePatternEnemys moveE;
RandamShot randomshot;
CircleShot circleshot;
BulletManager::BulletManager()
{
	selection = std::make_unique<int>(0);
}
void BulletManager::shot(AbstractEnemy* enemy)
{
	moveE.move(enemy);
	BulletSelect(enemy);
}
void BulletManager::BulletSelect(AbstractEnemy* enemy)
{
	int count = enemy->Getcount();
	int select =enemy->GetSelection();
	switch (select)
	{
	case Random:
			
			if (count > 100) {
				randomshot.Initialize(enemy->GetX(), enemy->GetY());
				randomshot.update(enemy->GetX(), enemy->GetY());
			}
			
		
		break;

	case Circle:
		if (count > 100) {
		
			circleshot.Initialize(enemy->GetX(), enemy->GetY());
			circleshot.update(enemy->GetX(), enemy->GetY());
		}
		break;
	default:
		break;
	}
}

void BulletManager::BulletDraw(AbstractEnemy*enemy)
{
	int select = enemy->GetSelection();
	const int count = enemy->Getcount();
	switch (select)
	{
	case Random:
		if (100 < count < 130) {
			randomshot.Draw();
		}
		
		break;

	case Circle:
		circleshot.Draw();
		break;
	default:
		break;
	}
}

