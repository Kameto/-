#include "LabyrinthScene.h"

LabyrinthScene::LabyrinthScene()
	: BaseGameScene()
{
	BaseGameScene::nowGameScene = GS_Name::eLabyrinth;
	myChara = new Player(MapData::GetCenterX(), MapData::GetCenterY());
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
	myChara->CharaUpdate();
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

	/**** debug�R�[�h ****/
	DrawFormatString(900, 0, 0xFFFFFF, "mcX : %d\nmcY : %d", MapData::GetCenterX(), MapData::GetCenterY());
	DrawFormatString(900, 64, 0xFFFFFF, "width : %d\nheight : %d", MapData::GetCenterX() * 2, MapData::GetCenterY() * 2);
	DrawFormatString(900, 128, 0xFFFFFF, "chara->cx : %d\nchara->cy : %d", myChara->cx, myChara->cy);
	BaseGameScene::NowSceneDraw();
	/*********************/
}