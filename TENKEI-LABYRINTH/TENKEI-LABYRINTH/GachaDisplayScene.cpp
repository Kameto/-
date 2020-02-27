#include "GachaDisplayScene.h"

GachaDisplayScene::GachaDisplayScene()
	: BaseGameScene()
{
	BaseGameScene::nowGameScene = GS_Name::eGachaDisplay;
	nowStone = 1000;
	stoneCount = 0;
	for (int i = 0; i < THIS_EVE; i++)
	{
		eventCount[i] = 0;
		eventFlag[i] = false;
	}
	roolCount = 0.0;
	roolFlag = false;
}

GachaDisplayScene::~GachaDisplayScene()
{
	nowStone = 0;
	stoneCount = 0;
	for (int i = 0; i < THIS_EVE; i++)
	{
		eventCount[i] = 0;
		eventFlag[i] = false;
	}
	roolCount = 0.0;
	roolFlag = false;
}

void GachaDisplayScene::GameUpdate()
{
	BaseGameScene::ChangeGameScene(GS_Name::eGameLoad);

	/**** �K�`���M�~�b�N ****/

	// �΂̓�������
	if (stoneCount < 10 && !eventFlag[0])
	{
		if (Keyboard::GetKey(KEY_INPUT_S) == 1)
		{
			stoneCount++;
			eventFlag[0] = true;
			eventCount[0] = 0;
		}
		else if(Keyboard::GetKey(KEY_INPUT_D) == 1)
		{
			stoneCount = 10;
			eventFlag[0] = true;
			eventCount[0] = 0;
		}
		else {}
	}

	// ��������
	if (eventFlag[0] == true)
	{
		if (eventCount[0] < 55){ eventCount[0]++; }
		else { eventFlag[0] = false; }
	}

	// ��]����(���菈��)
	if (Keyboard::GetKey(KEY_INPUT_G) == 1 && stoneCount == 10 && !roolFlag && !eventFlag[0])
	{
		roolFlag = true;
		roolCount = 0.0;
		nowStone -= stoneCount;
		stoneCount = 0;
	}

	// �n���h���̉�]����
	if (roolFlag)
	{
		if (roolCount < 6.0) { roolCount += 0.05; }
		else { roolFlag = false; }
	}
	/****************************/
}

void GachaDisplayScene::GameDraw()
{
	/**** �w�i�`�� ****/
	DrawBox(0,0,1920,1080, 0xFFCC99, true);
	DrawBoxAA(0, 0, 1920 - (int)(1.5 * 5), 1080 - (int)(1.5 * 5), 0xCC99FF, false, 10.0f);
	/******************/

	/**** �w�i�ȊO�̃I�u�W�F�N�g�`�� ****/
	
	// �p�C�v
	DrawBoxAA((float)(WND_WIDTH / 2 + 80), (float)(WND_HEIGHT / 2 + 142), 
		(float)(WND_WIDTH / 2 + 80 + 500), (float)(WND_HEIGHT / 2 + 142 + 32),
		0x000000, 2.0f);

	// �K�`��➑�
	DrawRotaGraph(WND_WIDTH / 2, WND_HEIGHT / 2, 1.0, 0.0, Graphics::GetMainGraphs("�K�`��"), true);
	DrawRotaGraph(WND_WIDTH / 2 + 80, WND_HEIGHT / 2 + 192, 1.0, roolCount, Graphics::GetMainGraphs("�n���h��"), true);

	// ������
	DrawGraph(1360, 540, Graphics::GetMainGraphs("������"), true);

	if (eventFlag[0])
	{
		if (eventCount[0] > 15)
		{
			DrawCircle((WND_WIDTH / 2) + 400 - ((eventCount[0] - 15) * 8), (WND_HEIGHT / 2 + 142), 40, 0xFFFF00, true);
		}
		else
		{
			DrawRotaGraph(1470, 400 + (eventCount[0] * 10), 4.0, 0.0, Graphics::GetItemGraphs("�A�C�e���A�C�R��"), true);
		}
	}
	
	// �A�C�e���J�E���^�[
	DrawRotaGraph(1470, 400, 3.0, 0.0, Graphics::GetMainGraphs("�J�E���g�t���[��"), true);
	DrawRotaGraph(1380, 400, 3.0, 0.0, Graphics::GetItemGraphs("�A�C�e���A�C�R��"), true);
	
	// ���O���̕\���G���A
	DrawGraph(256, 256, Graphics::GetMainGraphs("���O�G���A"), true);
	DrawGraph(1360, 96, Graphics::GetMainGraphs("�K�`�����e�g"), true);

	// ���l�E������\��
	DrawExtendFormatString(1420, 384, 3.0, 2.0, 0x000000, "%d", nowStone);

	// debug�m�F
	DrawFormatString(1200, 0, 0x000000, "%s : %.2f", STR(roolCount), roolCount);
	DrawFormatString(1200, 16, 0x000000, "%s : %d", STR(nowStone), nowStone);
	DrawFormatString(1200, 32, 0x000000, "%s : %d", STR(stoneCount), stoneCount);
	/************************************/
	BaseGameScene::NowSceneDraw();
}