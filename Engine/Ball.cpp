#include "Ball.h"


Ball::Ball(Color c)
{
	pos = Vec2(100.0f, 100.0f);
	r = Rect(pos, radius * 2, radius * 2);
}

void Ball::Draw(Graphics& gfx)
{
	SpriteCodex::DrawBall(Vec2(int(pos.x + radius), int(pos.y + radius)), gfx);
}

void Ball::DrawRectSw(Graphics& gfx, Color c)
{
	gfx.DrawRect(int(pos.x), int(pos.y), int(pos.x + radius * 2), int(pos.y + radius * 2), c);
}

void Ball::Update(float dt)
{
	pos += vel * dt;
}
