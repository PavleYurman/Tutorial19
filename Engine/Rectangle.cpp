#include "Rectangle.h"

Rect::Rect(const Vec2& upperLeft, float in_width, float in_hight)
{
	width = in_width;
	height = in_hight;
	left = upperLeft.x;
	up = upperLeft.y;
	right = left + in_width;
	down = up + height;
	center.x = width / 2.0f;
	center.y = width / 2.0f;
}

//Rectangle::Rectangle(const Vec2& upperLeft, const Vec2& downRight)
//{
//	left = upperLeft.x;
//	up = upperLeft.y;
//	right = downRight.x;
//	down = downRight.y;
//}

void Rect::Draw(Graphics& gfx, Color c)
{
	gfx.DrawRect(int(left), int(up), int(right), int(down), c);
}
