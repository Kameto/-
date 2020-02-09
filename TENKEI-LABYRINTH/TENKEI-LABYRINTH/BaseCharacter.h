#pragma once
#include "CameraData.h"
#include "DefFunc.h"
#include "Keyboard.h"
#include "MapData.h"

// ������`
typedef enum class Direction
{
	eNone,		// �����Ȃ�
	eUp,		// �����
	eDown,		// ������
	eRight,		// �E����
	eLeft,		// ������
	eChara_NUM	// ����
}Dir;

// �S�L�����N�^�[�̃x�[�X��`
class BaseCharacter
{
public:
	int cx;			// �}�b�v�p���W
	int cy;			// �}�b�v�p���W
	int dx;			// �`����W
	int dy;			// �`����W
	int sx;			// ���T�C�Y
	int sy;			// �c�T�C�Y
	Dir moveDir;	// �ړ�����
	Dir drawDir;	// �`�掞�\������

	BaseCharacter();
	BaseCharacter(const int _x, const int _y);
	~BaseCharacter();
	virtual void CharaUpdate() = 0;
	virtual void CharaDraw() = 0;

protected:
	inline bool CheckHitBody()
	{
		if ((MapData::CheckMapData(cx, cy - 1) == 0 && moveDir == Dir::eUp)
			|| (MapData::CheckMapData(cx, cy + 1) == 0 && moveDir == Dir::eDown)
			|| (MapData::CheckMapData(cx - 1, cy) == 0 && moveDir == Dir::eLeft)
			|| (MapData::CheckMapData(cx + 1, cy) == 0 && moveDir == Dir::eRight))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	void SetDrawPoint(const int _x, const int _y);
	void SetGraphSize(const int _gr);
};