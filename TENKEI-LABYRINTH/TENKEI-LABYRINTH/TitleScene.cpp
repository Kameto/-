#include "TitleScene.h"

TitleScene::TitleScene()
{

}

TitleScene::~TitleScene()
{

}

void TitleScene::UI_Update()
{

}

void TitleScene::UI_Draw()
{

}

void TitleScene::Update()
{
	UI_Update();
	BaseScene::ChangeScene(S_Name::eGame);
}

void TitleScene::Draw()
{
	UI_Draw();
	BaseScene::DrawDebugSceneData();
}