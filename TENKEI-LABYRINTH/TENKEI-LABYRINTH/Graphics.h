#pragma once
#include <map>
#include <vector>
#include "DefFunc.h"

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
	static void LoadMainGraphs();
	static void ReleaseMainGraphs();
	static int GetMainGraphs(const string name);
	static int GetMainGraphs(const int _num);

	static GraphList main;
};