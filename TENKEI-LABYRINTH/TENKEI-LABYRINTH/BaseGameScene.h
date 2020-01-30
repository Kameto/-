#pragma once
#include "DefFunc.h"
#include "Graphics.h"

typedef enum class GameSceneName
{
	eGameLoad,		// ���[�h���
	eLabyrinth,		// �T�����
	eSaveArea,		// �Z�[�u�G���A
	eBattle,		// �퓬���
	eStatusCheck,	// �X�e�[�^�X�m�F
	eSaveDisplay,	// �Z�[�u���
	eGachaDisplay,	// �K�`�����
	eSceneSize		// ����
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