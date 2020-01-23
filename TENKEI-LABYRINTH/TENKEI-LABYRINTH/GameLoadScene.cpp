#include "GameLoadScene.h"

GameLoadScene::GameLoadScene()
	: BaseGameScene()
{

}

GameLoadScene::~GameLoadScene()
{

}

void GameLoadScene::GameUpdate()
{
	BaseGameScene::ChangeGameScene();
}

void GameLoadScene::GameDraw()
{
	BaseGameScene::NowSceneDraw();
}