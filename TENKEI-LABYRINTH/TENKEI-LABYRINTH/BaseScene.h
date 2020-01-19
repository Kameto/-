#pragma once
#include "DefFunc.h"

typedef enum class SceneName
{
	eLoad,		// �摜���̓ǂݍ���
	eTitle,		// �^�C�g�����
	eGame,		// �Q�[���S�̏���
	eCredit		// �N���A���N���W�b�g
}S_Name;

class BaseScene
{
public:
	BaseScene();
	virtual ~BaseScene();
	virtual void UI_Update() = 0;
	virtual void UI_Draw() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	S_Name GetNowScene();
	void UpdateDebugSceneData(S_Name nextScene);
	void DrawDebugSceneData();

protected:
	static S_Name nowScene;
};