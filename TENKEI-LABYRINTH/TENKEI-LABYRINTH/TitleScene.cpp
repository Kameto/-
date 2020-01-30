#include "TitleScene.h"

TitleScene::TitleScene()
{
	for (int i = 0; i < 5; i++)
	{
		effectCounter[i] = 0;
	}
}

TitleScene::~TitleScene()
{
	for (int i = 0; i < 5; i++)
	{
		effectCounter[i] = 0;
	}
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

	DrawGraph(0, 0, Graphics::GetMainGraphs("�^�C�g���w�i"), true);
	DrawGraph(480, 150, Graphics::GetMainGraphs("�^�C�g��"), true);
	DrawFormatString(1500, 0, 0x000000, "size : %d", (unsigned)Graphics::player.graph.size());

	BaseScene::DrawDebugSceneData();
}