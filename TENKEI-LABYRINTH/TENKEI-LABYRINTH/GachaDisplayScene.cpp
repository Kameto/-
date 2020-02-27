#include "GachaDisplayScene.h"

GachaDisplayScene::GachaDisplayScene()
	: BaseGameScene()
{
	BaseGameScene::nowGameScene = GS_Name::eGachaDisplay;
	nowStone = 1000;
	stoneCount = 0;
	for (int i = 0; i < THIS_EVE; i++)
	{
		eventCount[i] = 0;
		eventFlag[i] = false;
	}
	roolCount = 0.0;
	roolFlag = false;
}

GachaDisplayScene::~GachaDisplayScene()
{
	nowStone = 0;
	stoneCount = 0;
	for (int i = 0; i < THIS_EVE; i++)
	{
		eventCount[i] = 0;
		eventFlag[i] = false;
	}
	roolCount = 0.0;
	roolFlag = false;
}

void GachaDisplayScene::GameUpdate()
{
	BaseGameScene::ChangeGameScene(GS_Name::eGameLoad);

	/**** ガチャギミック ****/

	// 石の投入処理
	if (stoneCount < 10 && !eventFlag[0])
	{
		if (Keyboard::GetKey(KEY_INPUT_S) == 1)
		{
			stoneCount++;
			eventFlag[0] = true;
			eventCount[0] = 0;
		}
		else if(Keyboard::GetKey(KEY_INPUT_D) == 1)
		{
			stoneCount = 10;
			eventFlag[0] = true;
			eventCount[0] = 0;
		}
		else {}
	}

	// 投入処理
	if (eventFlag[0] == true)
	{
		if (eventCount[0] < 55){ eventCount[0]++; }
		else { eventFlag[0] = false; }
	}

	// 回転処理(決定処理)
	if (Keyboard::GetKey(KEY_INPUT_G) == 1 && stoneCount == 10 && !roolFlag && !eventFlag[0])
	{
		roolFlag = true;
		roolCount = 0.0;
		nowStone -= stoneCount;
		stoneCount = 0;
	}

	// ハンドルの回転処理
	if (roolFlag)
	{
		if (roolCount < 6.0) { roolCount += 0.05; }
		else { roolFlag = false; }
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
	
	// パイプ
	DrawBoxAA((float)(WND_WIDTH / 2 + 80), (float)(WND_HEIGHT / 2 + 142), 
		(float)(WND_WIDTH / 2 + 80 + 500), (float)(WND_HEIGHT / 2 + 142 + 32),
		0x000000, 2.0f);

	// ガチャ筐体
	DrawRotaGraph(WND_WIDTH / 2, WND_HEIGHT / 2, 1.0, 0.0, Graphics::GetMainGraphs("ガチャ"), true);
	DrawRotaGraph(WND_WIDTH / 2 + 80, WND_HEIGHT / 2 + 192, 1.0, roolCount, Graphics::GetMainGraphs("ハンドル"), true);

	// 投入口
	DrawGraph(1360, 540, Graphics::GetMainGraphs("投入口"), true);

	if (eventFlag[0])
	{
		if (eventCount[0] > 15)
		{
			DrawCircle((WND_WIDTH / 2) + 400 - ((eventCount[0] - 15) * 8), (WND_HEIGHT / 2 + 142), 40, 0xFFFF00, true);
		}
		else
		{
			DrawRotaGraph(1470, 400 + (eventCount[0] * 10), 4.0, 0.0, Graphics::GetItemGraphs("アイテムアイコン"), true);
		}
	}
	
	// アイテムカウンター
	DrawRotaGraph(1470, 400, 3.0, 0.0, Graphics::GetMainGraphs("カウントフレーム"), true);
	DrawRotaGraph(1380, 400, 3.0, 0.0, Graphics::GetItemGraphs("アイテムアイコン"), true);
	
	// ログ等の表示エリア
	DrawGraph(256, 256, Graphics::GetMainGraphs("ログエリア"), true);
	DrawGraph(1360, 96, Graphics::GetMainGraphs("ガチャ内容枠"), true);

	// 数値・文字列表示
	DrawExtendFormatString(1420, 384, 3.0, 2.0, 0x000000, "%d", nowStone);

	// debug確認
	DrawFormatString(1200, 0, 0x000000, "%s : %.2f", STR(roolCount), roolCount);
	DrawFormatString(1200, 16, 0x000000, "%s : %d", STR(nowStone), nowStone);
	DrawFormatString(1200, 32, 0x000000, "%s : %d", STR(stoneCount), stoneCount);
	/************************************/
	BaseGameScene::NowSceneDraw();
}