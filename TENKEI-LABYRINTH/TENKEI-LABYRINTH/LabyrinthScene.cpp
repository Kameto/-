#include "LabyrinthScene.h"

LabyrinthScene::LabyrinthScene()
	: BaseGameScene()
{
	BaseGameScene::nowGameScene = GS_Name::eLabyrinth;
	myChara = new Player(MapData::GetCenterX(), MapData::GetCenterY());
	for (int i = 0; i < 5; i++)
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
	BaseGameScene::ChangeGameScene(GS_Name::eSaveArea);
	
	/**** �L�����N�^�[���� ****/
	if (!eventFlag[0])
	{
		myChara->CharaUpdate();

		// �v���C���[�����[�v�}�X�|�C���g�ɏ�������ʂ�؂�ւ���
		if (MapData::CheckMapData(myChara->cx, myChara->cy) == 2)
		{
			eventFlag[0] = true;
		}
	}
	else
	{
		WorpUpdate();
	}
	/**************************/

	/**** �J�������� ****/
	CameraData::Update(myChara->cx, myChara->cy);
	/********************/
}

void LabyrinthScene::GameDraw()
{
	/**** �}�b�v�`�� ****/
	MapData::Draw();
	/********************/

	/**** �L�����`�� ****/
	myChara->CharaDraw();
	/********************/

	/**** �G�t�F�N�g�`�� ****/
	if (eventFlag[0]) 
	{
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, eventCounter[0]);
		DrawCircle(WND_WIDTH / 2, WND_HEIGHT / 2, eventCounter[0] + ((eventCounter[0] * 4)), 0xFFFFFF, true);
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
	}
	/************************/

	/**** debug�R�[�h ****/
	DrawFormatString(900, 0, 0xFFFFFF, "mcX : %d\nmcY : %d", MapData::GetCenterX(), MapData::GetCenterY());
	DrawFormatString(900, 64, 0xFFFFFF, "width : %d\nheight : %d", MapData::GetCenterX() * 2, MapData::GetCenterY() * 2);
	DrawFormatString(900, 128, 0xFFFFFF, "chara->cx : %d\nchara->cy : %d", myChara->cx, myChara->cy);
	BaseGameScene::NowSceneDraw();
	/*********************/
}

void LabyrinthScene::WorpUpdate()
{
	if (eventCounter[0] < 255)
	{
		eventCounter[0]++;
	}
	else
	{
		nowGameScene = GameSceneName::eSaveArea;
	}
}