#include<Dxlib.h>
#include"SystemMain.h"
#include<crtdbg.h>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtDumpMemoryLeaks();
	//« « « « « « « «
	//‚±‚±‚©‚çˆ—

	SystemMain systemmain;
	if (systemmain.Initialize())
	{
		systemmain.main();
	}
	
	systemmain.finalize();
	
}