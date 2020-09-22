#include "Ball.h"


Ball::Ball(Color c)
{
	pos = Vec2(100.0f, 100.0f);
	r = Rect(pos, radius * 2, radius * 2);
}

void Ball::Draw(Graphics& gfx)
{
	SpriteCodex::DrawBall(r.center, gfx);
}

void Ball::DrawBorder(Graphics& gfx, Color c)
{
	gfx.DrawRect(int(pos.x - radius), int(pos.y - radius), int(pos.x + radius), int(pos.y + radius), c);
}

