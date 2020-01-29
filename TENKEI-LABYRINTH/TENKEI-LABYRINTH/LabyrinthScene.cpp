#include "LabyrinthScene.h"

LabyrinthScene::LabyrinthScene()
	: BaseGameScene()
{
	BaseGameScene::nowGameScene = GS_Name::eLabyrinth;
}

LabyrinthScene::~LabyrinthScene()
{

}

void LabyrinthScene::GameUpdate()
{
	BaseGameScene::ChangeGameScene(GS_Name::eSaveArea);
}

void LabyrinthScene::GameDraw()
{
	/**** �}�b�v�`�� ****/
	for (int i = 0; i < (WND_HEIGHT / 64) + 1; i++)
	{
		for (int j = 0; j < (WND_WIDTH / 64); j++)
		{
			if ((i * j) % 5 == 0)
			{
				DrawGraph(j * 64, i * 64, Graphics::GetMainGraphs("���"), true);
			}
			else
			{
				DrawGraph(j * 64, i * 64, Graphics::GetMainGraphs("�⏰"), true);
			}
		}
	}
	/********************/

	BaseGameScene::NowSceneDraw();
}