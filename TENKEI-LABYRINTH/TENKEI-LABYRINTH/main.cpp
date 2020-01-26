#include "DefFunc.h"
#include "SceneMgr.h"
#include "Graphics.h"

int _stdcall WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	SetMainWindowText("__�V�b���r�����X__ver.0.0.1");// �A�v���P�[�V������

	SetOutApplicationLogValidFlag(false);			// log�t�@�C���̐���
#ifdef _DEBUG
	ChangeWindowMode(true);							// �X�N���[���ݒ�
#else
	ChangeWindowMode(false);						// �X�N���[���ݒ�
#endif
	SetGraphMode(1920, 1080, 32);					// �`��͈�
	SetFontSize(16);								// �����T�C�Y�ݒ�
	if (DxLib_Init() == -1)							// Dx���C�u�����̏�����
	{
		return -1;
	}
	if (SetDrawScreen(DX_SCREEN_BACK) == -1)		// �w�i�`��ݒ�
	{
		return -1;
	}
	SetMouseDispFlag(false);						// �E�B���h�E���[�h�ł��}�E�X�J�[�\�����\���ɂ���

	// �|�C���^�[������
	Keyboard* key	 = new Keyboard();
	JoyPad* pad		 = new JoyPad();
	SceneMgr* smgr	 = new SceneMgr();
	Graphics* graph	 = new Graphics();
	graph->LoadMainGraphs();

	// ���b�Z�[�W���[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_END) == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();
		key->KeyUpdate();
		pad->Pad_Update();
		smgr->SceneUpdate();
		smgr->SceneDraw();
		if (smgr->GetEndInput()) { break; }
		ScreenFlip();
	}

	// �|�C���^�[���
	RELEASE(graph);
	RELEASE(smgr);
	RELEASE(pad);
	RELEASE(key);

	InitGraph();
	DxLib_End();

	return 0;
}