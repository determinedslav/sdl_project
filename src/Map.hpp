#pragma once

#include "Game.hpp"

class Map
{
public:

	Map();
	~Map();

	void LoadMap(int arr[20][25]);
	void DrawMap();

private:

	SDL_Rect src, dest;

	SDL_Texture* plane;
	SDL_Texture* forrest;
	SDL_Texture* mountain;

	int map[20][25];
};