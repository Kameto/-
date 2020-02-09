#pragma once
#include "BaseGameScene.h"
#include "Player.h"
#include  <array>

#define EFFECT_NUM 5

enum class BodyName
{
	eNone,		// ���L��
	eCircle,	// �~
	eBox,		// �����`�E�����`
	eTriangle,	// �O�p�`
	eBdy_NUM	// ����
};

class EffectBody
{
public:
	int eX;			// x���W
	int eY;			// y���W
	int eR;			// ���a
	int color;		// �F
	bool checkFlag;	// �m�F�p�t���O
	BodyName eBN;	// ����`�̖���

	EffectBody()
	{
		eX = 0;
		eY = 0;
		eR = 0;
		color = 0x000000;
		checkFlag = false;
		eBN = BodyName::eNone;
	}
	~EffectBody()
	{
		eX = 0;
		eY = 0;
		eR = 0;
		color = 0x000000;
		checkFlag = false;
		eBN = BodyName::eNone;
	}

	/**** �Z�b�^�[ ****/
	// �ʒu�A�傫���A�`��A�\���ۂ̎w��
	void SetData
	(
		const int _x,
		const int _y,
		const int _r,
		const bool flag,
		const BodyName _bn
	)
	{
		eX = _x;
		eY = _y;
		eR = _r;
		checkFlag = flag;
		eBN = _bn;
		if (this->eBN == BodyName::eCircle) { color = 0xFF0000; }
		else if (this->eBN == BodyName::eBox){ color = 0x00FF00; }
		else if (this->eBN == BodyName::eTriangle){ color = 0x0000FF; }
		else {}
	}
	// �F�w��
	void SetColor(const int _code)
	{
		color = _code;
	}
	/******************/

	/**** �����蔻�� ****/
	inline bool HitBody(BaseCharacter* chara)
	{
		if (this->eBN == BodyName::eCircle)
		{
			auto x = abs(this->eX - (chara->dx + 28));
			auto y = abs(this->eY - chara->dy);
			auto s = sqrt((x * x) + (y * y));
			if (s <= this->eR) { return true; }
			else { return false; }
		}
		else if (this->eBN == BodyName::eBox)
		{
			if (abs(this->eX + (chara->dx + 28)) < (this->eR + chara->sx) &&
				abs(this->eY + chara->dy) < (this->eR + chara->sy))
			{
				return true;
			}
			else { return false; }
		}
		else if (this->eBN == BodyName::eTriangle)
		{
			// ��Ŏ�������___after plug in
		}
		else { return false; }
	}
	/********************/

	/**** �`�� ****/
	void BodyDraw()
	{
		if (this->checkFlag)
		{
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);
			if (this->eBN == BodyName::eCircle)
			{
				DrawCircle(this->eX, this->eY, this->eR, color, true);
			}
			else if (this->eBN == BodyName::eBox)
			{
				DrawBox(this->eX - (this->eR / 2), this->eY - (this->eR / 2),
					this->eX + (this->eR / 2), this->eY + (this->eR / 2), color, true);
			}
			else if (this->eBN == BodyName::eTriangle)
			{
				// ��Ŏ�������___after plug in
			}
			else {}
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
		}
	}
	/**************/
};

class SaveAreaScene :
	public BaseGameScene
{
private:
	Player* mychara;
	int effectCounter[EFFECT_NUM];
	array<EffectBody*, EFFECT_NUM>effect;

public:
	SaveAreaScene();
	~SaveAreaScene();
	void GameUpdate();
	void GameDraw();
};