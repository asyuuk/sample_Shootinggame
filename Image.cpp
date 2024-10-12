#include "Image.h"
#include<DxLib.h>

Image::Image()
{
	player = std::make_unique<int>();
	enemy = std::make_unique<int>();
	*player = LoadGraphs("E:\\Aseprite\\bluearchiveyuuka.png");
	*enemy = LoadGraphs("E:\\Aseprite\\bluearchiveyuuka.png");
}

int& Image::LoadGraphs(const char * filename)
{
	int ret = LoadGraph(filename);
	Images.push_back(ret);
	return ret;
}

void Image::release()
{
	const int size = Images.size();
	for (int i = 0; i < size; i++)
	{
		DeleteGraph(Images[i]);
	}
	Images.clear();
}