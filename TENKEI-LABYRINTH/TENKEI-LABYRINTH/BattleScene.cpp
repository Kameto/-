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
	/**** 背景 ***/
	for (int i = 0, n = (WND_HEIGHT/ 64); i < n; i++)
	{
		for (int j = 0, m = (WND_WIDTH / 64); j < m; j++)
		{
			if ((i * 64) < (WND_HEIGHT / 3.5))
			{
				DrawGraph(j * 64, i * 64, Graphics::GetMainGraphs("岩壁"), true);
			}
			else
			{
				DrawGraph(j * 64, i * 64, Graphics::GetMainGraphs("岩床"), true);
			}
		}
	}
	for(int i = 0; i < (WND_WIDTH / 256) + 1; i++)
	{
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 200);
		DrawRotaGraph(i * 256, 160, 4.0, 0.0, Graphics::GetMainGraphs("岩壁"), true);
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
	}
	/*************/
	
	/**** コマンドエリア ****/
	DrawGraph(0, (WND_HEIGHT / 2) + 216, Graphics::GetMainGraphs("コマンドエリア"), true);
	/************************/

	BaseGameScene::NowSceneDraw();
}