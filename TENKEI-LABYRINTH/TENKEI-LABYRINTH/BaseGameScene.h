#pragma once
#include "DefFunc.h"

typedef enum class GameSceneName
{
	eGameLoad,		// ���[�h���
	eLabyrinth,		// �T�����
	eSaveArea,		// �Z�[�u�G���A
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
	void ChangeGameScene();
	void NowSceneDraw();

protected:
	static GS_Name nowGameScene;
};