#include "Paddle.h"

Paddle::Paddle(const Vec2& upperLeft, float width, float hight, Color c_in)
{
	r = Rect(upperLeft, width, hight);
	c = c_in;
}

void Paddle::Draw(Graphics& gfx)
{
	r.Draw( gfx, c );
	Rect rect_wh = Rect(r.left + 5, r.right - 5, r.up, r.down);
	rect_wh.Draw( gfx, Colors::White );
}

