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
	ball(Colors::Yellow),
	wal(),
	bounce_sound(L"Sounds\\arkpad.wav"),
	br(Vec2(50.0f, 50.0f), 75.0f, 25.0f, Colors::Green),
	pad( Vec2(400.0f, 500.0f), 78.0f, 30.0f, Colors::Red )
{	
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
		bounce_sound.Play();
	}
	//if ( br.Colide(ball) )
	//{
	//	br.isColided = true;
	//	ball.ChangeY();
	//}
	br.ProcessColison( ball );
}

void Game::ComposeFrame()
{	
	pad.Draw(gfx);
	ball.Draw(gfx);
	if ( !br.isColided )
	{
		br.Draw( gfx );
	}
	
	/*ball.DrawRectSw(gfx, Colors::Blue);*/
}
