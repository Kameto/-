#include "DefFunc.h"
#include "SceneMgr.h"
#include "Graphics.h"

int _stdcall WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	SetMainWindowText("__天恵ラビリンス__ver.0.0.1");// アプリケーション名

	SetOutApplicationLogValidFlag(false);			// logファイルの生成
#ifdef _DEBUG
	ChangeWindowMode(true);							// スクリーン設定
#else
	ChangeWindowMode(false);						// スクリーン設定
#endif
	SetGraphMode(1920, 1080, 32);					// 描画範囲
	SetFontSize(16);								// 文字サイズ設定
	if (DxLib_Init() == -1)							// Dxライブラリの初期化
	{
		return -1;
	}
	if (SetDrawScreen(DX_SCREEN_BACK) == -1)		// 背景描画設定
	{
		return -1;
	}
	SetMouseDispFlag(false);						// ウィンドウモードでもマウスカーソルを非表示にする

	// ポインター初期化
	Keyboard* key	 = new Keyboard();
	JoyPad* pad		 = new JoyPad();
	SceneMgr* smgr	 = new SceneMgr();
	Graphics* graph	 = new Graphics();
	graph->LoadMainGraphs();

	// メッセージループ
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

	// ポインター解放
	RELEASE(graph);
	RELEASE(smgr);
	RELEASE(pad);
	RELEASE(key);

	InitGraph();
	DxLib_End();

	return 0;
}