#include "Graphics.h"

GraphList Graphics::main;

Graphics::Graphics()
{
	main.graphName.resize(0);
}

Graphics::~Graphics()
{
	ReleaseMainGraphs();
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
}

int Graphics::GetMainGraphs(const string name)
{
	return main.graph.at(name);
}

int Graphics::GetMainGraphs(const int _num)
{
	return main.graph.at(main.graphName.at(_num));
}