#include "LabyrinthScene.h"

LabyrinthScene::LabyrinthScene()
	: BaseGameScene()
{

}

LabyrinthScene::~LabyrinthScene()
{

}

void LabyrinthScene::GameUpdate()
{
	BaseGameScene::ChangeGameScene(GS_Name::eGameLoad);
}

void LabyrinthScene::GameDraw()
{
	BaseGameScene::NowSceneDraw();
}