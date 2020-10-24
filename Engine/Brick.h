#pragma once
#include "Rectangle.h"
#include "Graphics.h"
#include "Colors.h"
#include "Ball.h"

class Brick
{
public:
	Brick() = default;
	Brick(const Vec2& upperLeft, float width, float hight, Color c_in);
	Rect r;
	Color c;
	bool isColided = true;
public:
	bool CheckForColision( Ball& bl );
	Vec2 getCenter() const;
	bool Ovrlaping(Ball& bl);
	void ExecuteColison(Ball& bl);
	void Draw( Graphics& gfx );
};