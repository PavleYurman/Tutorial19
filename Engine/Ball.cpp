#include "Ball.h"


Ball::Ball(const Vec2& pos_in, const Vec2& vel_in, Color c)
	:
	pos(pos_in),
	vel(vel_in)
{
	r = Rect(Vec2(pos.x - radius, pos.y - radius), Vec2(pos.x + radius, pos.y + radius));
}

Ball::Ball(Color c)
{
	pos = Vec2(100.0f, 100.0f);
	r = Rect(Vec2(pos.x - radius, pos.y - radius), Vec2(pos.x + radius, pos.y + radius));
}

void Ball::Draw(Graphics& gfx)
{
	SpriteCodex::DrawBall(pos, gfx);
}

void Ball::DrawRectSw(Graphics& gfx, Color c)
{
	gfx.DrawRect(int(pos.x), int(pos.y), int(pos.x + radius * 2), int(pos.y + radius * 2), c);
}

void Ball::Update(float dt)
{
	pos += vel * dt;	
}

bool Ball::isCollided(Wall& wl)
{
	bool collision = false;
	r = Rect( Vec2( pos.x - radius, pos.y - radius ), Vec2( pos.x + radius , pos.y + radius ) );
	// predpostavimo odboj vedno samo od ene stranice, nikoli od dveh hkrati
	if (r.down >= wl.rectangle.down)
	{
		collision = true;
		chng_inY = true;
		chng_inX = false;
	}
	else if (r.up <= wl.rectangle.up)
	{
		collision = true;
		chng_inY = true;
		chng_inX = false;
	}
	if (r.left <= wl.rectangle.left)
	{
		collision = true;
		chng_inY = false;
		chng_inX = true;
	}
	else if (r.right >= wl.rectangle.right)
	{
		collision = true;
		chng_inY = false;
		chng_inX = true;
	}


	return collision;
}

void Ball::ChangeX()
{
	vel.x = -vel.x;
}

void Ball::ChangeY()
{
	vel.y = -vel.y;
}

void Ball::Rebound(Wall& wl)
{
	if (isCollided(wl))
	{
		if (chng_inY)
		{
			ChangeY();
			if (r.down > wl.rectangle.down)
			{
				pos.y -= r.down - wl.rectangle.down;
			}
			else if(r.up < wl.rectangle.up)
			{
				pos.y += wl.rectangle.up - r.up;
			}
		}
		else if(chng_inX)
		{
			ChangeX();
			if (r.left < wl.rectangle.left)
			{
				pos.x += wl.rectangle.left - r.left;
			}
			else if(r.right > wl.rectangle.right)
			{
				pos.x -= r.right - wl.rectangle.right;
			}
		}

	}
}




