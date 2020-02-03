#include "Graphics.h"

GraphList Graphics::main;
GraphList Graphics::player;
GraphList Graphics::item;
GraphList Graphics::number;
mutex Graphics::mtx;

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

/**** Mainフォルダ画像 ****/
void Graphics::LoadMainGraphs()
{
	lock_guard<mutex>lock(mtx);
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
/**************************/

/**** Playerフォルダ画像 ****/
void Graphics::LoadPlayerGraph()
{
	lock_guard<mutex>lock(mtx);
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
/****************************/

/**** Itemフォルダ画像 ****/
void Graphics::LoadItemGraph()
{
	lock_guard<mutex>lock(mtx);
	for (const fs::directory_entry& x : fs::directory_iterator("graph\\item"))
	{
		const string address = x.path().string<char>();
		const string name = x.path().stem().string<char>();
		item.graph.insert(make_pair(name, LoadGraph(address.c_str())));
		item.graphName.push_back(name);
	}
}

void Graphics::ReleaseItemGraph()
{
	for (int i = 0, n = (unsigned)item.graph.size(); i < n; i++)
	{
		DeleteGraph(item.graph.at((item.graphName.at(i))));
	}
	item.graph.erase(item.graph.begin(), item.graph.end());
	item.graphName.erase(item.graphName.begin(), item.graphName.end());
	item.graphName.shrink_to_fit();
}

int Graphics::GetItemGraphs(const string name)
{
	return item.graph.at(name);
}
/**************************/

void Graphics::LoadNumberGraph()
{
	lock_guard<mutex>lock(mtx);
	for (const fs::directory_entry& x : fs::directory_iterator("graph\\number"))
	{
		const string address = x.path().string<char>();
		const string name = x.path().stem().string<char>();
		number.graph.insert(make_pair(name, LoadGraph(address.c_str())));
		number.graphName.push_back(name);
	}
}

void Graphics::ReleaseNumberGraph()
{
	for (int i = 0, n = (unsigned)number.graph.size(); i < n; i++)
	{
		DeleteGraph(number.graph.at((number.graphName.at(i))));
	}
	number.graph.erase(number.graph.begin(), number.graph.end());
	number.graphName.erase(number.graphName.begin(), number.graphName.end());
	number.graphName.shrink_to_fit();
}

int Graphics::GetNumberGraphs(const string name)
{
	return number.graph.at(name);
}