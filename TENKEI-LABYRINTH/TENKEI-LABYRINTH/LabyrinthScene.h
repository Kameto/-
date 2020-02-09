#pragma once
#include "BaseGameScene.h"
#include "CameraData.h"
#include "MapData.h"
#include "Player.h"

// �C�x���g����
enum EventName
{
	eWorp,		// �Z�[�u��ʂɈړ�
	eBattle,	// �o�g�����
	eEve_NUM	// ����
};

typedef class LabyrinthScene
	: public BaseGameScene
{
private:
	Player* myChara;

	/**** �C�x���g�����p�ϐ� ****/
	int eventCounter[EventName::eEve_NUM];
	bool eventFlag[EventName::eEve_NUM];
	/****************************/

public:
	LabyrinthScene();
	~LabyrinthScene();
	void GameUpdate();
	void GameDraw();

	/**** �C�x���g���� ****/
	bool EventCheck();
	void WorpUpdate();
	void BattleUpdate();
	/**********************/

}Lab_Scene;