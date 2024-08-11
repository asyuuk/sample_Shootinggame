#include "Background.h"
#include<DxLib.h>
void Background::SetDraw()
{
	handle = LoadGraph("E:\\Aseprite\\background_b.png");
	graphhandle = MakeScreen(384, 448, FALSE);
	DrawGraph(0, 0, handle, FALSE);
}

void Background::Draw() const
{
	SetDrawScreen(graphhandle);
	
	
}

void Background::DrawEnd()
{
	SetDrawScreen(DX_SCREEN_BACK);
	DrawGraph(32, 16, graphhandle, FALSE);
}