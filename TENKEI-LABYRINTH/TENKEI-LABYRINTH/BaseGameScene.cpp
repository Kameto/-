#include "BaseGameScene.h"

GS_Name BaseGameScene::nowGameScene = GS_Name::eGameLoad;

BaseGameScene::BaseGameScene()
{

}

BaseGameScene::~BaseGameScene() 
{

}

GS_Name BaseGameScene::GetNowGameScene()
{
	return this->nowGameScene;
}