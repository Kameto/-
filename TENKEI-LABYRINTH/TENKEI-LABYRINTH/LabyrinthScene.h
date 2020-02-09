#pragma once
#include "BaseGameScene.h"
#include "CameraData.h"
#include "MapData.h"
#include "Player.h"

// イベント名称
enum EventName
{
	eWorp,		// セーブ画面に移動
	eBattle,	// バトル画面
	eEve_NUM	// 総数
};

typedef class LabyrinthScene
	: public BaseGameScene
{
private:
	Player* myChara;

	/**** イベント処理用変数 ****/
	int eventCounter[EventName::eEve_NUM];
	bool eventFlag[EventName::eEve_NUM];
	/****************************/

public:
	LabyrinthScene();
	~LabyrinthScene();
	void GameUpdate();
	void GameDraw();

	/**** イベント処理 ****/
	bool EventCheck();
	void WorpUpdate();
	void BattleUpdate();
	/**********************/

}Lab_Scene;