#include "Rectangle.h"

Rect::Rect(const Vec2& upperLeft, float in_width, float in_hight)
{
	width = in_width;
	height = in_hight;
	left = upperLeft.x;
	up = upperLeft.y;
	right = left + width;
	down = up + height;
	center = upperLeft;
}

Rect::Rect(const Vec2& upperLeft, const Vec2& downRight)
{
	left = upperLeft.x;
	up = upperLeft.y;
	right = downRight.x;
	down = downRight.y;
	width = right - left;
	height = up - down;
	center = Vec2( width / 2.0f, height / 2.0 );

}

void Rect::Draw(Graphics& gfx, Color c)
{
	gfx.DrawRect(int(left), int(up), int(right), int(down), c);
}
