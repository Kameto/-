#pragma once
#include "CameraData.h"
#include "DefFunc.h"
#include "Keyboard.h"
#include "MapData.h"

// 方向定義
typedef enum class Direction
{
	eNone,		// 方向なし
	eUp,		// 上方向
	eDown,		// 下方向
	eRight,		// 右方向
	eLeft,		// 左方向
	eChara_NUM	// 総数
}Dir;

// 全キャラクターのベース定義
class BaseCharacter
{
public:
	int cx;			// マップ用座標
	int cy;			// マップ用座標
	int dx;			// 描画座標
	int dy;			// 描画座標
	int sx;			// 横サイズ
	int sy;			// 縦サイズ
	Dir moveDir;	// 移動方向
	Dir drawDir;	// 描画時表示方向

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