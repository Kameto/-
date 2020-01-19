#include "GameScene.h"

GameScene::GameScene()
{

}

GameScene::~GameScene()
{

}

void GameScene::UI_Update()
{

}

void GameScene::UI_Draw()
{

}

void GameScene::Update()
{
	UI_Update();
	BaseScene::UpdateDebugSceneData(S_Name::eCredit);
}

void GameScene::Draw()
{
	UI_Draw();
	BaseScene::DrawDebugSceneData();
}