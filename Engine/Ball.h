#pragma once
#include "SpriteCodex.h"
#include "Vec2.h"
#include "Graphics.h"
#include "Rectangle.h"
#include "SpriteCodex.h"
#include "Wall.h"

class Ball
{
public:
	Ball() = default;
	Ball(const Vec2& pos, const Vec2& vel, Color c);
	Ball(Color c);
	void Draw(Graphics& gfx);
	void DrawRectSw(Graphics& gfx, Color c);
	void Ball::Update(float dt);
	bool isCollided(Wall& wl);
	void ChangeX();
	void ChangeY();
	void Rebound(Wall& wl);
	static Rect GenerateRect();
public:
	Vec2 pos;
	Vec2 vel = Vec2(150.0f, 150.0f);
	Rect r;
	bool chng_inX = false;
	bool chng_inY = false;
	
	float radius = 7.0f;
};