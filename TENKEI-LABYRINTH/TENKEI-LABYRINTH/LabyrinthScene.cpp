#include "LabyrinthScene.h"

LabyrinthScene::LabyrinthScene()
	: BaseGameScene()
{
	BaseGameScene::nowGameScene = GS_Name::eLabyrinth;
	myChara = new Player(MapData::GetCenterX(), MapData::GetCenterY());
	for (int i = 0, n = EventName::eEve_NUM; i < n; i++)
	{
		eventCounter[i] = 0;
		eventFlag[i] = false;
	}
}

LabyrinthScene::~LabyrinthScene()
{
	RELEASE(myChara);
	MapData::UnsetData();
	CameraData::UnsetData();
}

void LabyrinthScene::GameUpdate()
{
	/**** debugコード ****/
	BaseGameScene::ChangeGameScene(GS_Name::eSaveArea);
	/*********************/

	/**** キャラクター処理 ****/
	if (EventCheck())
	{
		myChara->CharaUpdate();

		// プレイヤーがワープマスポイントに乗ったらフラグを立てる
		if (MapData::CheckMapData(myChara->cx, myChara->cy) == 2)
		{
			eventFlag[EventName::eWorp] = true;
		}

		// debugコード
		if (Keyboard::GetKey(KEY_INPUT_B) == 1)
		{
			eventFlag[EventName::eBattle] = true;
		}
	}
	else
	{
		if (eventFlag[EventName::eWorp]) { WorpUpdate(); }
		if (eventFlag[EventName::eBattle]) { BattleUpdate(); }
	}
	/**************************/

	/**** カメラ処理 ****/
	CameraData::Update(myChara->cx, myChara->cy);
	/********************/
}

void LabyrinthScene::GameDraw()
{
	/**** マップ描画 ****/
	MapData::Draw();
	/********************/

	/**** キャラ描画 ****/
	myChara->CharaDraw();
	/********************/

	/**** エフェクト描画 ****/
	if (eventFlag[EventName::eWorp])
	{
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, eventCounter[0]);
		DrawCircle(WND_WIDTH / 2, WND_HEIGHT / 2, eventCounter[0] + ((eventCounter[0] * 4)), 0xFFFFFF, true);
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
	}
	if(eventFlag[EventName::eBattle])
	{
		for (int i = 0, n = 8; i < n; i++)
		{
			DrawBox(0, i * (WND_HEIGHT / 8), 
				1920, i * (WND_HEIGHT / 8) + eventCounter[EventName::eBattle], 0x000000, true);
		}
	}
	/************************/

	/**** debugコード ****/
	DrawFormatString(900, 0, 0xFFFFFF, "mcX : %d\nmcY : %d", MapData::GetCenterX(), MapData::GetCenterY());
	DrawFormatString(900, 64, 0xFFFFFF, "width : %d\nheight : %d", MapData::GetCenterX() * 2, MapData::GetCenterY() * 2);
	DrawFormatString(900, 128, 0xFFFFFF, "chara->cx : %d\nchara->cy : %d", myChara->cx, myChara->cy);
	BaseGameScene::NowSceneDraw();
	/*********************/
}

bool LabyrinthScene::EventCheck()
{
	bool check = true;
	for (int i = 0, n = EventName::eEve_NUM; i < n; i++)
	{
		if(eventFlag[i])
		{
			check = false;
			break;
		}
	}
	return check;
}

void LabyrinthScene::WorpUpdate()
{
	if (eventCounter[EventName::eWorp] < 255)
	{
		eventCounter[EventName::eWorp]++;
	}
	else
	{
		nowGameScene = GameSceneName::eSaveArea;
	}
}

void LabyrinthScene::BattleUpdate()
{
	if (eventCounter[EventName::eBattle] < (WND_HEIGHT / 8))
	{
		eventCounter[EventName::eBattle]+=2;
	}
	else
	{
		nowGameScene = GameSceneName::eBattle;
	}
}