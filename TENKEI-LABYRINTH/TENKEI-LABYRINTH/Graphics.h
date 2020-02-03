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
	/**** main�t�H���_�摜 ****/
	static void LoadMainGraphs();
	static void ReleaseMainGraphs();
	static int GetMainGraphs(const string name);
	/**** Player�摜 ****/
	static void LoadPlayerGraph();
	static void ReleasePlayerGraph();
	static int GetPlayerGraphs(const string name);
	/**** item�t�H���_�摜 ****/
	static void LoadItemGraph();
	static void ReleaseItemGraph();
	static int GetItemGraphs(const string name);
	/**** number�t�H���_�摜 ****/
	static void LoadNumberGraph();
	static void ReleaseNumberGraph();
	static int GetNumberGraphs(const string name);

	static GraphList main;
	static GraphList player;
	static GraphList item;
	static GraphList number;
	static mutex mtx;
};