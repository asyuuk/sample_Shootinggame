#pragma once
#include<stack>
#include<memory>
#include"AbstructScene.h"
#include"GameScene.h"
using namespace std;
class SceneClass
{
public:
	SceneClass();
	~SceneClass() = default;
	bool SceneLoop();
	void SceneChange();
private:
	stack< shared_ptr<AbstructScene>>_sceneStack;
};

