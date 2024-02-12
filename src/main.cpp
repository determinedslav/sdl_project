#include "Game.hpp"

Game* game = nullptr;

int main(int argc, char *argv[])
{

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();

	game->init("bsod", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	while (game->running()) 
	{
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		// framerate limiter, might be changed in the future because it looks like a hack to me
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();
	//SDL_Init(SDL_INIT_EVERYTHING);
	//SDL_Window *window = SDL_CreateWindow("bsod", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	//SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

	//SDL_SetRenderDrawColor(renderer, 63, 63, 255, 255);

	//SDL_RenderClear(renderer);

	//SDL_RenderPresent(renderer);

	//SDL_Delay(5000);

	return 0;

}