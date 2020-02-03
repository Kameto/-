#include "LoadScene.h"

LoadScene::LoadScene()
{
	loadFlag = false;
	fade = 0;
	time = 0;
}

LoadScene::~LoadScene()
{
	loadFlag = false;
	fade = 0;
	time = 0;
}

void LoadScene::UI_Update()
{
	// なんか必要になったら書く
}

void LoadScene::UI_Draw()
{
	// なんか必要になったら書く
}

void LoadScene::Update()
{
	UI_Update();

	if (time <= 400) { time++; }
	else { BaseScene::ChangeScene(S_Name::eTitle); }

	if (time % 100 == 0 && time <= 400) { fade += (1920 / 4); }
	if (!loadFlag)
	{
		// なんでできないのかわからない
		// 一括処理
		/*
		vThs.push_back(thread ([] {Graphics::LoadMainGraphs(); }));
		vThs.push_back(thread ([] {Graphics::LoadPlayerGraph(); }));
		vThs.push_back(thread ([] {Graphics::LoadItemGraph(); }));
		vThs.push_back(thread ([] {Graphics::LoadNumberGraph(); }));
		for (int i = 0, n = (unsigned)vThs.size(); i < n; i++)
		{
			vThs.at(i).join();
			if (!vThs.at(i).joinable())
			{
				continue;
			}
		}
		*/

		// 個別処理
		thread th1([] { Graphics::LoadMainGraphs(); });
		thread th2([] { Graphics::LoadPlayerGraph(); });
		thread th3([] { Graphics::LoadItemGraph(); });
		thread th4([] { Graphics::LoadNumberGraph(); });

		th1.join();
		th2.join();
		th3.join();
		th4.join();
		loadFlag = true;
	}
}

void LoadScene::Draw()
{
	UI_Draw();

	DrawBox(0, 0, fade, 1080, 0x997700, true);
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);
	DrawBox(0, 0, 1920, 1080, 0xFFFFFF, true);
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);

	// 画像ハンドルのアドレスを表示
	for (int i = 0, n = (unsigned)Graphics::main.graph.size(); i < n; i++)
	{
		DrawFormatString(1650, i * 32, 0xFFFFFF, "%d : %d", i, Graphics::main.graph.at(Graphics::main.graphName.at(i)));
	}
	DrawFormatString(1400,0,0xFFFFFF, "time : %d", time);

	BaseScene::DrawDebugSceneData();
}