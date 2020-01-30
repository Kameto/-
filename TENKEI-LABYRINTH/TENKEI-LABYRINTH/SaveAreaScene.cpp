#include "SaveAreaScene.h"

SaveAreaScene::SaveAreaScene()
	: BaseGameScene()
{
	BaseGameScene::nowGameScene = GS_Name::eSaveArea;

	for (int i = 0, n = EFFECT_NUM; i < n; i++)
	{
		effectCounter[i] = 0;
	}
}

SaveAreaScene::~SaveAreaScene()
{
	for (int i = 0, n = EFFECT_NUM; i < n; i++)
	{
		effectCounter[i] = 0;
	}
}

void SaveAreaScene::GameUpdate()
{
	BaseGameScene::ChangeGameScene(GS_Name::eBattle);

	/**** エフェクト処理 ****/
	if (effectCounter[0] > 0)
	{
		effectCounter[0]--;
	}
	else
	{
		effectCounter[0] = 255;
	}
	/************************/
}

void SaveAreaScene::GameDraw()
{
	/**** 背景描画 ****/
	DrawBox(0,0,WND_WIDTH, WND_HEIGHT, 0x993300, true);
	for (int i = 0; i < (WND_HEIGHT / 128) + 1; i++)
	{
		for (int j = 0; j < (WND_WIDTH / 128); j++)
		{
			DrawGraph(j * 128, i * 128, Graphics::GetMainGraphs("岩肌"), true);
		}
	}
	/******************/

	/**** 背景以外のオブジェクト描画 ****/
	for (int i = 0; i < (WND_HEIGHT / 64) + 1; i++)
	{
		for (int j = 0; j < (WND_WIDTH / 64); j++)
		{
			if(i == 0 || i == (WND_HEIGHT / 64) || j == 0 || j == (WND_WIDTH / 64))
			{
				if (j > 10 && j < 19)
				{
					DrawGraph(j * 64, i * 64, Graphics::GetMainGraphs("岩床"), true);
				}
				else
				{
					DrawGraph(j * 64, i * 64, Graphics::GetMainGraphs("岩壁"), true);
				}
			}
			DrawBox(j * 64, i * 64, j * 64 + 64, i * 64 + 64, 0xFF0000, false);
		}
	}
	DrawRotaGraph(WND_WIDTH / 2, WND_HEIGHT / 2, 1.0, 0.0, Graphics::GetMainGraphs("セーブポイント"), true);
	DrawRotaGraph(WND_WIDTH / 2, WND_HEIGHT / 2 - 16, 1.0, 0.0, Graphics::GetPlayerGraphs("Chara0"), true);
	/************************************/

	/**** エフェクト描画 ****/
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 255 - effectCounter[0]);
	DrawCircle(WND_WIDTH / 2, WND_HEIGHT / 2, 48 + effectCounter[0], 0x777777);
	DrawCircle(WND_WIDTH / 2, WND_HEIGHT / 2, 64 + effectCounter[0], 0x444444);
	DrawCircle(WND_WIDTH / 2, WND_HEIGHT / 2, 96 + effectCounter[0], 0x111111);
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
	/************************/

	/**** debug ****/
#ifdef _DEBUG
	// エフェクトカウンター
	for (int i = 0, n = EFFECT_NUM; i < n; i++)
	{
		DrawFormatString(1500, i * 32, 0xFFFFFF, "counter[%d] : %d", i, effectCounter[i]);
	}
#endif
	/***************/

	BaseGameScene::NowSceneDraw();
}