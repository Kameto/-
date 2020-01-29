#include "GameLoadScene.h"

GameLoadScene::GameLoadScene()
	: BaseGameScene()
{
	BaseGameScene::nowGameScene = GS_Name::eGameLoad;
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