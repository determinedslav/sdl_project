#include "Game.hpp"
#include "TextureManager.hpp"
//#include "GameObject.hpp"
#include "Map.hpp"
//#include "ECS/ECS.hpp"
#include "ECS/Components.hpp"
#include "Vector2D.hpp"
#include "Collision.hpp"

//GameObject* player;
//GameObject* enemy;
//SDL_Texture* playerTex;
//SDL_Rect srcR, destR;

Map* map;
Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

std::vector<ColliderComponent*> Game::colliders;

auto& player(manager.addEntity());
auto& enemy(manager.addEntity());
auto& wall(manager.addEntity());

auto& tile0(manager.addEntity());
auto& tile1(manager.addEntity());
auto& tile2(manager.addEntity());

Game::Game()
{}
Game::~Game()
{}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Obamna" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Windows 9" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		{
			SDL_SetRenderDrawColor(renderer, 63, 63, 255, 255);
			std::cout << "Windows 9.6" << std::endl;
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}

	//player = new GameObject("assets/Sw.png", 0, 0);
	//enemy = new GameObject("assets/Ax.png", 96, 96);
	map = new Map();

	//newPlayer.addComponent<PositionComponent>();

	tile0.addComponent<TileComponent>(200, 200, 32, 32, 0);
	tile1.addComponent<TileComponent>(300, 200, 32, 32, 1);
	tile2.addComponent<TileComponent>(200, 300, 32, 32, 2);
	tile2.addComponent<ColliderComponent>("mountain");

	player.addComponent<TransformComponent>(2);
	player.addComponent<SpriteComponent>("assets/Sw.png");
	player.addComponent<KeyboardController>();
	player.addComponent<ColliderComponent>("player");

	enemy.addComponent<TransformComponent>(96, 96);
	enemy.addComponent<SpriteComponent>("assets/Ax.png");

	wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
	wall.addComponent<SpriteComponent>("assets/Mountainv1.png");
	wall.addComponent<ColliderComponent>("wall");

	//playerTex = TextureManager::LoadTexture("Sw.png", renderer);

	//SDL_Surface* tmpSurface = IMG_Load("Sw.png");
	//playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	//SDL_FreeSurface(tmpSurface);
}

void Game::handleEvents()
{
	SDL_PollEvent(&event);
	switch (event.type){
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}
}

void Game::update()
{

	//player->Update();
	//enemy->Update();
	manager.refresh();
	manager.update();
	//player.getComponent<TransformComponent>().position.Add(Vector2D(5, 0));

	//if (player.getComponent<TransformComponent>().position.x > 100)
	//{
	//	player.getComponent<SpriteComponent>().setTex("assets/La.png");
	//}

	//if (Collision::AABB(player.getComponent<ColliderComponent>().collider, wall.getComponent<ColliderComponent>().collider))
	//{
	//	//this is very buggy
	//	player.getComponent<TransformComponent>().velocity * -1;
	//	std::cout << "Walled" << std::endl;
	//}

	for (auto cc : colliders)
	{
		Collision::AABB(player.getComponent<ColliderComponent>(), *cc);
	}

	cnt++;
	//destR.h = 32;
	//destR.w = 32;
	//destR.x = cnt / 2;
	//destR.y = cnt / 5;

	std::cout << cnt << std::endl;
	//std::cout << newPlayer.getComponent<PositionComponent>().x() << "," << newPlayer.getComponent<PositionComponent>().y() << std::endl;
}

void Game::render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	//player->Render();
	//enemy->Render();
	//SDL_RenderCopy(renderer, playerTex, NULL, &destR);
	manager.draw();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Gane Ober" << std::endl;
}