#include "Paddle.h"

Paddle::Paddle(const Vec2& upperLeft, float width, float hight, Color c_in)
{
	r = Rect(upperLeft, width, hight);
	c = c_in;
}

void Paddle::Draw(Graphics& gfx)
{
	r.Draw( gfx, c );
	rect_wh = Rect(r.left + 5, r.right - 5, r.up, r.down);
	rect_wh.Draw( gfx, Colors::White );
}

void Paddle::Move(const Keyboard& kbd, float dt, const Wall& wl)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		r.left -= speed * dt;
		r.right -= speed * dt;
	}
	else if (kbd.KeyIsPressed(VK_RIGHT))
	{
		r.left += speed * dt;
		r.right += speed * dt;
	}
}

bool Paddle::Colision(const Wall& wl)
{
	return false;
}

