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
	BaseScene::DrawDebugSceneData();

	DrawGraph(300, 150, Graphics::GetMainGraphs("ƒ^ƒCƒgƒ‹"), true);

	for (int i = 0, n = (unsigned)Graphics::main.graph.size(); i < n; i++)
	{
		DrawFormatString(1650, i * 32, 0xFFFFFF, "%d : %d", i, Graphics::main.graph.at(Graphics::main.graphName.at(i)));
	}
}