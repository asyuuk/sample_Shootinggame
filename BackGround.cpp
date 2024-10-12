#include "BackGround.h"
#include<DxLib.h>
BackGround::BackGround()
{
	_x = std::make_unique<float>(0);
	_y = std::make_unique<float>(0);
	handle = std::make_unique<int>(0);
	handlemake = std::make_unique<int>(0);

	

}
BackGround::~BackGround()
{
	DeleteGraph(*handle);
	DeleteGraph(*handlemake);
}

bool BackGround::update()
{
	return true;
}


void BackGround::draw()
{
	*handle = LoadGraph("E:\\Aseprite\\haikei_game.png");
	*handlemake = MakeScreen(384, 448, FALSE);
	
	SetDrawScreen(*handlemake);
	
	

}

void BackGround::drawback()
{
	SetDrawScreen(DX_SCREEN_BACK);
	DrawGraph(0, 0, *handle, FALSE);
	DrawGraph(32, 16, *handlemake, FALSE);
}



