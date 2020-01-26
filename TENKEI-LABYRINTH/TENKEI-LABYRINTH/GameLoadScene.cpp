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
	BaseGameScene::ChangeGameScene(GS_Name::eLabyrinth);
}

void GameLoadScene::GameDraw()
{
	BaseGameScene::NowSceneDraw();
}