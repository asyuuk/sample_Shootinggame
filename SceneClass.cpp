#include "SceneClass.h"

SceneClass::SceneClass()
{
	_sceneStack.push(make_shared<GameScene>());
}

bool SceneClass::SceneLoop()
{
	_sceneStack.top()->update();
	_sceneStack.top()->draw();
	return true;
}

void SceneClass::SceneChange()
{

	
}
