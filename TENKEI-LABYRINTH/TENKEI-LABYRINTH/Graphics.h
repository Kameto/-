#pragma once
#include <map>
#include <vector>
#include "DefFunc.h"
#include <mutex>

class GraphList
{
public:
	map<string, int>graph;
	vector<string>graphName;
};

class Graphics
{
public:
	Graphics();
	~Graphics();
	/**** mainフォルダ画像 ****/
	static void LoadMainGraphs();
	static void ReleaseMainGraphs();
	static int GetMainGraphs(const string name);
	/**** Player画像 ****/
	static void LoadPlayerGraph();
	static void ReleasePlayerGraph();
	static int GetPlayerGraphs(const string name);
	/**** itemフォルダ画像 ****/
	static void LoadItemGraph();
	static void ReleaseItemGraph();
	static int GetItemGraphs(const string name);
	/**** numberフォルダ画像 ****/
	static void LoadNumberGraph();
	static void ReleaseNumberGraph();
	static int GetNumberGraphs(const string name);

	static GraphList main;
	static GraphList player;
	static GraphList item;
	static GraphList number;
	static mutex mtx;
};