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
	BaseScene::ChangeScene(S_Name::eTitle);
}

void LoadScene::Draw()
{
	UI_Draw();

	DrawGraph(0, 0, Graphics::GetMainGraphs("タイトル背景"), true);
	DrawGraph(480, 150, Graphics::GetMainGraphs("タイトル"), true);


	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);
	DrawBox(0, 0, 1920, 1080, 0xFFFFFF, true);
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);

	for (int i = 0, n = (unsigned)Graphics::main.graph.size(); i < n; i++)
	{
		DrawFormatString(1650, i * 32, 0xFFFFFF, "%d : %d", i, Graphics::main.graph.at(Graphics::main.graphName.at(i)));
	}

	BaseScene::DrawDebugSceneData();
}