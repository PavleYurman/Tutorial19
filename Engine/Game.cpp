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



Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	ball( Vec2(371.0f, 280.0f), Vec2(-50.0f, -50.0f) ),
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
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	float dt = ft.Mark();		
	ball.Update( dt );
	ball.Rebound( wal );	
	if ( ball.isCollided( wal ) )
	{
		wal_sound.Play();
	}
	
	bool colisionHapppened = false;
	for (int i = 1; i < 48; i++)
	{	
		if ( !brics[ i ].isColided && brics[ i ].Colide(ball))
		{
			Vec2 br_centerCur = Vec2( (brics[ i - 1 ].r.left + brics[ i - 1 ].r.right) / 2.0f,
				(brics[ i - 1 ].r.up + brics[ i - 1 ].r.down) / 2.0f);
			Vec2 br_centerNew = Vec2( (brics[ i ].r.left + brics[ i ].r.right) / 2.0f,
				(brics[ i ].r.up + brics[ i ].r.down) / 2.0f );
			Vec2 vecNew = br_centerNew - ball.pos;
			Vec2 vecCurrent = ball.pos - br_centerCur;
			colisionHapppened = true;
			if (colisionHapppened && vecNew.GetLengthSq() < vecCurrent.GetLengthSq() )
			{				
				brics[i].isColided = true;
				ball.ChangeY();
				brick_sound.Play();
			}
			else
			{
				if ( (ball.pos.x >= brics[ i ].r.left) && (ball.pos.x <= brics[i].r.right) )
				{
					ball.ChangeY();
				}
				else //if ( ( bl.pos.x < r.left ) || ( bl.pos.x > r.right ) )
				{
					ball.ChangeX();
				}
				brics[i].isColided = true;				
				brick_sound.Play();
			}
			break;
			
		}						
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
	//if (!br.isColided)
	//{
	//	br.Draw(gfx);
	//}
	//if (!br1.isColided)
	//{
	//	br1.Draw(gfx);
	//}

}
