#include "LoadScene.h"

LoadScene::LoadScene()
{

}

LoadScene::~LoadScene()
{

}

void LoadScene::UI_Update()
{

}

void LoadScene::UI_Draw()
{

}

void LoadScene::Update()
{
	UI_Update();
	BaseScene::UpdateDebugSceneData(S_Name::eTitle);
}

void LoadScene::Draw()
{
	UI_Draw();
	BaseScene::DrawDebugSceneData();
}