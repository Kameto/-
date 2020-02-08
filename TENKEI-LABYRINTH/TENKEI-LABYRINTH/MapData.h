#pragma once
#include "CameraData.h"
#include "DefFunc.h"
#include "Graphics.h"
#include "MyRand.h"
#include <vector>
class MapData
{
private:
	static vector<vector<int>>mapdata;
	static int px;
	static int py;

public:
	MapData();
	~MapData();

	/**** ゲッター ****/
	// ミニマップ用プレイヤー座標取得
	inline static void SetPlayerPoint(int& _x, int& _y)
	{
		px = _x;
		py = _y;
	}
	// キャラ判定用座標取得
	inline static int CheckMapData(int _x, int _y)
	{
		return mapdata.at(_y).at(_x);
	}
	// 中央値の取得
	static int GetCenterY();
	// 中央値の取得
	static int GetCenterX();
	/******************/

	/**** 処理 ****/
	static void Draw();
	/**************/

	/**** 設定 ****/
	static void SetMapData();
	static void UnsetData();
	/**************/
};