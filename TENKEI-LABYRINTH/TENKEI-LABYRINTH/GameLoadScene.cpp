#include "GameLoadScene.h"

GameLoadScene::GameLoadScene()
	: BaseGameScene()
{
	BaseGameScene::nowGameScene = GS_Name::eGameLoad;
	MapData::SetMapData();
	CameraData::SetMapCenter(MapData::GetCenterY(), MapData::GetCenterX());
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