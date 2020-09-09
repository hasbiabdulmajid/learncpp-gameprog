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

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
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
}

void Game::ComposeFrame()
{
	const int x = 590;
	const int y = 490;
	/*x line left*/
	gfx.PutPixel(x+5, y + 10, 255, 255, 255); /*(x,y,color(r,g,b))*/
	gfx.PutPixel(x+6, y + 10, 255, 255, 255);
	gfx.PutPixel(x+7, y + 10, 255, 255, 255);

	/*x line right*/
	gfx.PutPixel(x+13, y + 10, 255, 255, 255);
	gfx.PutPixel(x+14, y + 10, 255, 255, 255);
	gfx.PutPixel(x+15, y+10, 255, 255, 255);

	/*y line upside*/
	gfx.PutPixel(x+10, y+5, 255, 255, 255);
	gfx.PutPixel(x + 10, y+6, 255, 255, 255);
	gfx.PutPixel(x + 10, y+7, 255, 255, 255);

	/*y line downside*/
	gfx.PutPixel(x + 10, y+13, 255, 255, 255);
	gfx.PutPixel(x + 10, y+14, 255, 255, 255);
	gfx.PutPixel(x + 10, y+15, 255, 255, 255);
}
