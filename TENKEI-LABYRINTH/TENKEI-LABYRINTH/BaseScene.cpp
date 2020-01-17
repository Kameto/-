#include "BaseScene.h"

S_Name BaseScene::nowScene = S_Name::eLoad;

S_Name BaseScene::GetNowScene()
{
	return this->nowScene;
}