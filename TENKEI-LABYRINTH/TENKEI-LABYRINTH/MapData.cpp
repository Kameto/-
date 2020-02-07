#include "MapData.h"

vector<vector<int>>MapData::mapdata;
int MapData::px;
int MapData::py;

MapData::MapData()
{
	SetMapData();
}

MapData::~MapData()
{
	UnsetData();
}

int MapData::GetCenterY()
{
	return (unsigned)mapdata.size() / 2;
}

int MapData::GetCenterX()
{
	return (unsigned)mapdata.at(GetCenterY()).size() / 2;
}

void MapData::Draw()
{
	for (int i = 0, n = (unsigned)MapData::mapdata.size(); i < n; i++)
	{
		for (int j = 0, m = (unsigned)MapData::mapdata.at(i).size(); j < m; j++)
		{
			if (MapData::mapdata.at(i).at(j) == 0)
			{
				DrawGraph((j + CameraData::GetCameraX()) * 64 , (i + CameraData::GetCameraY()) * 64,
					Graphics::GetMainGraphs("岩壁"), true);
			}
			else if (MapData::mapdata.at(i).at(j) == 1)
			{
				DrawGraph((j + CameraData::GetCameraX()) * 64, (i + CameraData::GetCameraY()) * 64,
					Graphics::GetMainGraphs("岩床"), true);
			}
			else
			{
				DrawGraph((j + CameraData::GetCameraX()) * 64, (i + CameraData::GetCameraY()) * 64,
					Graphics::GetMainGraphs("ワープポイント"), true);
			}
		}
	}
	
	// ミニマップ
	for (int i = 0, n = (unsigned)MapData::mapdata.size(); i < n; i++)
	{
		for (int j = 0, m = (unsigned)MapData::mapdata.at(i).size(); j < m; j++)
		{
			if (MapData::mapdata.at(i).at(j) == 0)
			{
				DrawBox(1350 + (j * 4), (i * 4), 1350 + (j * 4) + 4, (i * 4) + 4, 0xFFFFFF, true);
			}
			else if (MapData::mapdata.at(i).at(j) == 1)
			{
				DrawBox(1350 + (j * 4), (i * 4), 1350 + (j * 4) + 4, (i * 4) + 4, 0x000000, true);
			}
			else
			{
				DrawBox(1350 + (j * 4), (i * 4), 1350 + (j * 4) + 4, (i * 4) + 4, 0xFF0000, true);
			}
			if (i == py && j == px)
			{
				DrawBox(1350 + (j * 4), (i * 4), 1350 + (j * 4) + 4, (i * 4) + 4, 0x00FF00, true);
			}
		}
	}
}

void MapData::SetMapData()
{
	// 一応消しているか確認する
	UnsetData();

	const int mapSize = ((MyRand::GetRand() % 15) + 1) * 10;
	const int pointMax = ((MyRand::GetRand() % 5) + 1);
	mapdata.resize(mapSize);
	for (int i = 0, w = 0; i < mapSize; i++)
	{
		mapdata.at(i).resize(mapSize);
		for (int j = 0; j < mapSize; j++)
		{
			if (i == 0 || i + 1 == mapSize || j == 0 || j + 1 == mapSize) 
			{
				mapdata.at(i).at(j) = 0;
			}
			else
			{
				if (MyRand::GetRand() % 15 == 0 && pointMax > w)
				{
					mapdata.at(i).at(j) = 2;
					w++;
				}
				else
				{
					if (MyRand::GetRand() % 5 == 0)
					{
						mapdata.at(i).at(j) = 0;
					}
					else
					{
						mapdata.at(i).at(j) = 1;
					}
				}
			}
		}
	}
}

void MapData::UnsetData()
{
	if (!mapdata.empty())
	{
		for (int i = 0, n = (unsigned)mapdata.size(); i < n; i++)
		{
			mapdata.at(i).erase(mapdata.at(i).begin(), mapdata.at(i).end());
			mapdata.at(i).shrink_to_fit();
		}
		mapdata.erase(mapdata.begin(), mapdata.end());
		mapdata.shrink_to_fit();
	}
}