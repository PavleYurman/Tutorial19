#include "Rectangle.h"

Rect::Rect(float left_in, float right_in, float up_in, float bottom_in)
	:
	left(left_in),
	right(right_in),
	up(up_in),
	down(bottom_in)
{

}

Rect::Rect(const Vec2& upperLeft, float in_width, float in_hight)
	:
	Rect(upperLeft, Vec2(upperLeft.x + in_width, upperLeft.y + in_hight))
{
	
}

Rect::Rect(const Vec2& upperLeft, const Vec2& downRight)
	:
	Rect(upperLeft.x, downRight.x, upperLeft.y, downRight.y)
{
		
	//center = Vec2(upperLeft.x + (width / 2.0f), upperLeft.y + (height / 2.0f));

}

Rect Rect::GenerateRect(const Vec2& upperLeft, float width, float hight)
{	
	return Rect(Vec2(upperLeft.x - (width / 2.0f), upperLeft.y - (width / 2.0f)), Vec2(upperLeft.x + (width / 2.0f), upperLeft.y + (width / 2.0f)));
}

void Rect::Draw(Graphics& gfx, Color c)
{
	gfx.DrawRect(int(left), int(up), int(right), int(down), c);
}
