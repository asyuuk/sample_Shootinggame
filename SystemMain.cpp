#include "SystemMain.h"
#include<DxLib.h>
#include"SceneClass.h"

bool SystemMain::Initialize()const
{
	SetAlwaysRunFlag(TRUE);
	SetWindowSizeChangeEnableFlag(TRUE);
	SetOutApplicationLogValidFlag(TRUE);
	SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_DESKTOP);
	SetWindowText("bulletshooting");
	ChangeWindowMode(TRUE);
	
	if (DxLib_Init())
	{
		return false;
	}

	SetDrawScreen(DX_SCREEN_BACK);
	return true;
}

void SystemMain::finalize()const
{
	DxLib_End();
}

void SystemMain::main()const 
{
	SceneClass sceneclass;
	while ( !ScreenFlip() && !ProcessMessage() && !ClearDrawScreen() )
	{
		if ( !sceneclass.SceneLoop() )
		{
			break;
		}
	}
}