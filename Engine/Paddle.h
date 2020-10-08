#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Ball.h"
#include "Wall.h"

class Paddle
{
public:
	Paddle(const Vec2& upperLeft, float width, float hight, Color c_in);
	void Draw(Graphics& gfx);
public:
	Rect r;
	Color c;
};