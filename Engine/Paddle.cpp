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
	ProcColision(wl);
}

void Paddle::ProcColision(const Wall& wl)
{
	if (r.left  <= wl.rectangle.left )
	{
		float diff_out = wl.rectangle.left - r.left;
		r.left += diff_out;
		r.right += diff_out;
	}
	else if ( r.right >= wl.rectangle.right )
	{
		float diff_out = r.right - wl.rectangle.right;
		r.left -= diff_out;
		r.right -= diff_out;
	}	
}

void Paddle::Bounce(Ball& bl)
{
	if (bl.vel.y > 0.0 && r.up <= bl.r.down && r.left <= bl.r.right && r.right >= bl.r.left )
	{
		bl.ChangeY();
	}
}


