/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "Vec2.h"
#include <math.h>



Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	ball( Vec2(569.0f, 580.0f), Vec2(-350.0f, -350.0f) ),
	wal(),
	wal_sound(L"Sounds\\arkpad.wav"),
	brick_sound(L"Sounds\\arkbrick.wav"),
	pad(Vec2(400.0f, 500.0f), 78.0f, 30.0f, Colors::Red)
	

{	
	Color c[6] = { Colors::Blue, Colors::Green, Colors::Gray, Colors::Magenta, Colors::Red, Colors::Cyan };
	int i = 0;
	for (int y = 0; y < 6; y++)
	{
		for (int x = 0; x < 8; x++)
		{			
			brics[i] = Brick((Vec2(80.0f, 80.0f) + Vec2(x * br_width, y * br_height)), br_width, br_height, c[y]);
			i++;
		}
	}	
/*	br = Brick(Vec2(80.0f, 80.0f) + Vec2(br_width, br_height), br_width, br_height, Colors::Green);
	br1 = Brick(Vec2(160.0f, 80.0f) + Vec2(br_width, br_height), br_width, br_height, Colors::Green);*/	
}

void Game::Go()
{
	gfx.BeginFrame();
	// elapsed time frame of 16ms is devided into smaller time frames of 1.0ms making the game more responsive
	float elapsedTime = ft.Mark(); // this screen has 16ms refresh rate
	while ( elapsedTime > 0.0f )
	{
		const float dt = std::min(0.025f, elapsedTime);
		UpdateModel(dt);
		elapsedTime -= dt;
	}
	
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel( float dt )
{			
	ball.Update( dt );
	ball.Rebound( wal );	
	if ( ball.isCollided( wal ) )
	{
		wal_sound.Play();
		pad.coldown = false;
	}
	
	//bool colisionHapppened = false;	
	//Vec2 vecCurrent(0.0f, 0.0f);
	bool colisionHappened = false;
	int index;
	Vec2 vecCurrent(0.0f, 0.0f);
	Vec2 vecNew(0.0f, 0.0f);
	Vec2 br_centerNew(0.0f, 0.0f);
	for (int i = 0; i < 48; i++)
	{			
		if ( brics[ i ].CheckForColision(ball) )
		{		
			Vec2 br_centerNew = brics[i].getCenter();

			if (colisionHappened)
			{
			vecNew = br_centerNew - ball.pos;			
				if (vecNew.GetLengthSq() < vecCurrent.GetLengthSq())
				{					
					index = i;	// I understand :) stari index povozimo z novim			
					vecCurrent = vecNew;
				}
			}
			else
			{						
				index = i;				
				colisionHappened = true;
				vecCurrent = vecNew;
			}		
		}	
		
	}
	
	if (colisionHappened)
	{
		brics[index].ExecuteColison(ball);
		brick_sound.Play();
		pad.coldown = false;
	}

	//br.ProcessColison(ball);
	//br1.ProcessColison(ball);
	pad.Move(wnd.kbd, dt, wal);
	pad.Bounce( ball );
}

void Game::ComposeFrame()
{	
	pad.Draw(gfx);
	ball.Draw(gfx);	
	for (int i = 0; i < 48; i++)
	{	
		if (!brics[i].isColided)
		{
			brics[i].Draw( gfx );			
		}	
	}
}
