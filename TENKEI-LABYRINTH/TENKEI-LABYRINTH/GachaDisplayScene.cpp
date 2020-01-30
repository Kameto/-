#include "GachaDisplayScene.h"

GachaDisplayScene::GachaDisplayScene()
	: BaseGameScene()
{
	BaseGameScene::nowGameScene = GS_Name::eGachaDisplay;
}

GachaDisplayScene::~GachaDisplayScene()
{

}

void GachaDisplayScene::GameUpdate()
{
	BaseGameScene::ChangeGameScene(GS_Name::eGameLoad);
}

void GachaDisplayScene::GameDraw()
{
	/**** �w�i�`�� ****/
	DrawBox(0,0,1920,1080, 0xFFCC99, true);
	DrawBoxAA(0, 0, 1920 - (int)(1.5 * 5), 1080 - (int)(1.5 * 5), 0xCC99FF, false, 10.0f);
	/******************/
	/**** �w�i�ȊO�̃I�u�W�F�N�g�`�� ****/
	DrawRotaGraph(WND_WIDTH / 2, WND_HEIGHT / 2, 1.0, 0.0, Graphics::GetMainGraphs("�K�`��"), true);
	DrawRotaGraph(WND_WIDTH / 2 + 80, WND_HEIGHT / 2 + 192, 1.0, 0.0, Graphics::GetMainGraphs("�n���h��"), true);
	/************************************/
	BaseGameScene::NowSceneDraw();
}