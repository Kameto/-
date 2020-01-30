#pragma once
#include "DefFunc.h"
#include "Graphics.h"

typedef enum class GameSceneName
{
	eGameLoad,		// ロード画面
	eLabyrinth,		// 探索画面
	eSaveArea,		// セーブエリア
	eBattle,		// 戦闘画面
	eStatusCheck,	// ステータス確認
	eSaveDisplay,	// セーブ画面
	eGachaDisplay,	// ガチャ画面
	eSceneSize		// 総数
}GS_Name;

class BaseGameScene
{
public:
	BaseGameScene();
	virtual ~BaseGameScene();
	virtual void GameUpdate() = 0;
	virtual void GameDraw() = 0;
	GS_Name GetNowGameScene();
	void ChangeGameScene(GS_Name nextScene);
	void NowSceneDraw();

protected:
	static GS_Name nowGameScene;
};