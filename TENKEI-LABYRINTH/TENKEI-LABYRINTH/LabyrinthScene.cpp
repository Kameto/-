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
	BaseGameScene::ChangeGameScene();
}

void LabyrinthScene::GameDraw()
{
	BaseGameScene::NowSceneDraw();
}