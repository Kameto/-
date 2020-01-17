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
	BaseScene() {}
	virtual ~BaseScene() {}
	virtual void Update() = 0;
	virtual void Draw() = 0;
	S_Name GetNowScene();

protected:
	static S_Name nowScene;
};