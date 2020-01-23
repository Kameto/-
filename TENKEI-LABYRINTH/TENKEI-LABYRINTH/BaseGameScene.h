#pragma once
#include "DefFunc.h"

typedef enum class GameSceneName
{
	eGameLoad,		// ロード画面
	eLabyrinth,		// 探索画面
	eSaveArea,		// セーブエリア
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
	void ChangeGameScene();
	void NowSceneDraw();

protected:
	static GS_Name nowGameScene;
};