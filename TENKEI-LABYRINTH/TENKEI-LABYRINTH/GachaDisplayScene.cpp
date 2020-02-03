#include "GachaDisplayScene.h"

GachaDisplayScene::GachaDisplayScene()
	: BaseGameScene()
{
	BaseGameScene::nowGameScene = GS_Name::eGachaDisplay;
	nowStone = 1000;
	stoneCount = 0;
	roolCount = 0.0;
	roolFlag = false;
}

GachaDisplayScene::~GachaDisplayScene()
{
	nowStone = 0;
	stoneCount = 0;
	roolCount = 0.0;
	roolFlag = false;
}

void GachaDisplayScene::GameUpdate()
{
	BaseGameScene::ChangeGameScene(GS_Name::eGameLoad);

	/**** ガチャ回転ギミック ****/
	if (Keyboard::GetKey(KEY_INPUT_S) == 1 && stoneCount < 10)
	{
		stoneCount++;
	}

	if (Keyboard::GetKey(KEY_INPUT_G) == 1 && !roolFlag && stoneCount == 10)
	{
		roolFlag = true;
		roolCount = 0.0;
		nowStone -= stoneCount;
		stoneCount = 0;
	}

	if (roolFlag)
	{
		if (roolCount < 6.0)
		{
			roolCount += 0.05;
		}
		else
		{
			roolFlag = false;
		}
	}
	/****************************/
}

void GachaDisplayScene::GameDraw()
{
	/**** 背景描画 ****/
	DrawBox(0,0,1920,1080, 0xFFCC99, true);
	DrawBoxAA(0, 0, 1920 - (int)(1.5 * 5), 1080 - (int)(1.5 * 5), 0xCC99FF, false, 10.0f);
	/******************/
	/**** 背景以外のオブジェクト描画 ****/
	DrawRotaGraph(WND_WIDTH / 2, WND_HEIGHT / 2, 1.0, 0.0, Graphics::GetMainGraphs("ガチャ"), true);
	DrawRotaGraph(WND_WIDTH / 2 + 80, WND_HEIGHT / 2 + 192, 1.0, roolCount, Graphics::GetMainGraphs("ハンドル"), true);
	DrawRotaGraph(1470, 400, 3.0, 0.0, Graphics::GetMainGraphs("カウントフレーム"), true);
	DrawRotaGraph(1380, 400, 3.0, 0.0, Graphics::GetItemGraphs("アイテムアイコン"), true);
	DrawExtendFormatString(1420, 384, 3.0, 2.0, 0x000000, "%d", nowStone);

	// debug確認
	DrawFormatString(1200, 0, 0x000000, "%s : %.2f", STR(roolCount), roolCount);
	DrawFormatString(1200, 16, 0x000000, "%s : %d", STR(nowStone), nowStone);
	DrawFormatString(1200, 32, 0x000000, "%s : %d", STR(stoneCount), stoneCount);
	/************************************/
	BaseGameScene::NowSceneDraw();
}