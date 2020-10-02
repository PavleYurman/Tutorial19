#pragma once
#include "Vec2.h"
#include "Graphics.h"

class Rect
{
public:
	Rect() = default;
	Rect(float left_in, float right_in, float up_in, float bottom_in);
	Rect(const Vec2& upperLeft, float width, float hight);
	Rect(const Vec2& upperLeft, const Vec2& downRight);
	void Draw(Graphics& gfx, Color c);

public:
	float left;
	float up;
	float right;
	float down;
	/*Vec2 center;*/

};