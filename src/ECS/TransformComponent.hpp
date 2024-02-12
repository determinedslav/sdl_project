#pragma once

#include "../Vector2D.hpp"
//#include "Components.hpp"

class TransformComponent : public Component
{
//private:
//	int xpos;
//	int ypos;

public:
	//void init() override
	//{
	//	xpos = 0;
	//	ypos = 0;
	//}

	Vector2D position;
	Vector2D velocity;

	int height = 32;
	int width = 32;
	int scale = 1;

	int speed = 3;

	TransformComponent()
	{
		//xpos = 0;
		//ypos = 0;

		position.Zero();
	}

	TransformComponent(int sc)
	{
		position.Zero();
		scale = sc;
	}

	TransformComponent(float x, float y)
	{
		position.Zero();
	}

	TransformComponent(float x, float y, int h, int w, int sc)
	{
		position.x = x;
		position.y = y;
		height = h;
		width = w;
		scale = sc;
	}

	void init() override
	{
		velocity.Zero();
	}

	void update() override
	{
		//xpos++;
		//ypos++;

		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}

	//int x() { return xpos; }
	//void x(int x) { xpos = x; }
	//int y() { return ypos; }
	//void y(int y) { ypos = y; }

	//void setPos(int x, int y)
	//{
	//	xpos = x;
	//	ypos = y;
	//}
};