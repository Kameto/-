#include "MapData.h"

vector<vector<int>>MapData::mapdata;

MapData::MapData()
{
	SetMapData();
}

MapData::~MapData()
{
	UnsetData();
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

	for (int i = 0, n = (unsigned)MapData::mapdata.size(); i < n; i++)
	{
		for (int j = 0, m = (unsigned)MapData::mapdata.at(i).size(); j < m; j++)
		{
			DrawFormatString(1200 + j * 16, i * 16, 0x000000, "%d", MapData::mapdata.at(i).at(j));
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
	int a = 0;
}

void MapData::UnsetData()
{
	if (!mapdata.empty())
	{
		for (int i = 0, n = (unsigned)mapdata.size(); i < n; i++)
		{
			mapdata.at(i).erase(mapdata.at(i).begin(), mapdata.at(i).end());
		}
		mapdata.erase(mapdata.begin(), mapdata.end());
		mapdata.shrink_to_fit();
	}
}

int MapData::GetCenterX()
{
	return (unsigned)mapdata.at(GetCenterY()).size() / 2;
}

int MapData::GetCenterY()
{
	return (unsigned)mapdata.size() / 2;
}