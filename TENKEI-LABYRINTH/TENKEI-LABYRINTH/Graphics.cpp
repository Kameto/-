#include "Graphics.h"

GraphList Graphics::main;
GraphList Graphics::player;

Graphics::Graphics()
{
	main.graphName.resize(0);
	player.graphName.resize(0);
}

Graphics::~Graphics()
{
	ReleaseMainGraphs();
	ReleasePlayerGraph();
}

void Graphics::LoadMainGraphs()
{
	for (const fs::directory_entry& x : fs::directory_iterator("graph/main"))
	{
		const string address = x.path().string<char>();
		const string name = x.path().stem().string<char>();
		main.graph.insert(make_pair(name, LoadGraph(address.c_str())));
		main.graphName.push_back(name);
	}
}

void Graphics::ReleaseMainGraphs()
{
	for (int i = 0, n = (unsigned)main.graph.size(); i < n; i++)
	{
		DeleteGraph(main.graph.at((main.graphName.at(i))));
	}
	main.graph.erase(main.graph.begin(), main.graph.end());
	main.graphName.erase(main.graphName.begin(), main.graphName.end());
	main.graphName.shrink_to_fit();
}

int Graphics::GetMainGraphs(const string name)
{
	return main.graph.at(name);
}

int Graphics::GetMainGraphs(const int _num)
{
	return main.graph.at(main.graphName.at(_num));
}

void Graphics::LoadPlayerGraph()
{
	for (const fs::directory_entry& x : fs::directory_iterator("graph\\chara\\player"))
	{
		const string address = x.path().string<char>();
		const string name = x.path().stem().string<char>();
		player.graph.insert(make_pair(name, LoadGraph(address.c_str())));
		player.graphName.push_back(name);
		int a = 0;
	}
}

void Graphics::ReleasePlayerGraph()
{
	for (int i = 0, n = (unsigned)player.graph.size(); i < n; i++)
	{
		DeleteGraph(player.graph.at((player.graphName.at(i))));
	}
	player.graph.erase(player.graph.begin(), player.graph.end());
	player.graphName.erase(player.graphName.begin(), player.graphName.end());
	player.graphName.shrink_to_fit();
}

int Graphics::GetPlayerGraphs(const string name)
{
	return player.graph.at(name);
}