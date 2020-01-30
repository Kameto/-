#include "BattleScene.h"

BattleScene::BattleScene()
	: BaseGameScene()
{
	BaseGameScene::nowGameScene = GS_Name::eBattle;
}

BattleScene::~BattleScene()
{

}

void BattleScene::GameUpdate()
{
	BaseGameScene::ChangeGameScene(GS_Name::eGachaDisplay);
}

void BattleScene::GameDraw()
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < (WND_WIDTH / 64); j++)
		{
			if (i % 4 == 0 && j % 4 == 0)
			{
				DrawRotaGraph(j * 64 + 32, i * 64 + 32, 2.0, 0.0, Graphics::GetMainGraphs("壁"), true);
			}
			else
			{
				DrawGraph(j * 64, i * 64, Graphics::GetMainGraphs("岩壁"), true);
			}
		}
	}
	for (int i = 0; i < 10; i ++)
	{
		for (int j = 0; j < (WND_WIDTH / 64); j++)
		{
			DrawRotaGraph(j * 96 + 32, (64 * 7) + i * 96, 1.5, 0.0, Graphics::GetMainGraphs("岩床"), true);
		}
	}
	DrawGraph(0, (WND_HEIGHT / 2) + 216, Graphics::GetMainGraphs("コマンドエリア"), true);

	BaseGameScene::NowSceneDraw();
}