#include "CreditScene.h"

CreditScene::CreditScene()
{

}

CreditScene::~CreditScene()
{

}

void CreditScene::UI_Update()
{

}

void CreditScene::UI_Draw()
{

}

void CreditScene::Update()
{
	UI_Update();
	BaseScene::ChangeScene(S_Name::eLoad);
}

void CreditScene::Draw()
{
	UI_Draw();
	BaseScene::DrawDebugSceneData();
}