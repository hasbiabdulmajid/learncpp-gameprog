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
	if (wnd.kbd.KeyIsPressed(VK_UP)) {
		if (inhibitUp) {

		}
		else {
			vy = vy - 1;
			inhibitUp = true;
		}
		
		/*x line left*/
	}
	else {
		inhibitUp = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		if (inhibitDown) {

		}
		else {
			vy = vy + 1;
			inhibitDown = true;
		}
		
		/*x line left*/
	}
	else {
		inhibitDown = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		if (inhibitLeft) {

		}
		else {
			vx = vx - 1;
			inhibitLeft = true;
		}
		
		/*x line left*/
	}
	else {
		inhibitLeft = false;
	}


	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		if (inhibitRight) {

		}
		else {
			vx = vx + 1;
			inhibitRight = true;
		}
		
		/*x line left*/
	}
	else {
		inhibitRight = false;
	}

	x = x + vx;
	y = y + vy;

	// X Boundaries
	if (x + 5 >= gfx.ScreenWidth) {
		x = gfx.ScreenWidth - 6;
		vx = 0;
		vy = 0;
	}
	if (x - 5 < 0){
		x = 5;
		vx = 0;
		vy = 0;
	}

	// Y Boundaries 
	if (y + 5 >= gfx.ScreenHeight) {
		y = gfx.ScreenHeight - 6;
		vy = 0;
		vx = 0;
	}
	if (y - 5 < 0) {
		y = 5;
		vy = 0;
		vx = 0;
	}

	// Changing color specific region
	if (x > 30 && x < 150) {
		rg = 0;
	}
	else {
		rg = 255;
	}

	if (wnd.kbd.KeyIsPressed(VK_CONTROL)) {
		rg = 0;

	}
	shapeIsChanged = wnd.kbd.KeyIsPressed(VK_SPACE);
}

void Game::ComposeFrame()
{
	
		
	if (shapeIsChanged) {
		gfx.PutPixel(x - 3, y+3, rg, rg, 255); 
		gfx.PutPixel(x - 4, y+4, rg, rg, 255);
		gfx.PutPixel(x - 5, y+5, rg, rg, 255);

		gfx.PutPixel(x + 3, y-3, rg, rg, 255);
		gfx.PutPixel(x + 4, y-4, rg, rg, 255);
		gfx.PutPixel(x + 5, y-5, rg, rg, 255);

		gfx.PutPixel(x-3, y - 3, rg, rg, 255);
		gfx.PutPixel(x-4, y - 4, rg, rg, 255);
		gfx.PutPixel(x-5, y - 5, rg, rg, 255);

		gfx.PutPixel(x+3, y + 3, rg, rg, 255);
		gfx.PutPixel(x+4, y + 4, rg, rg, 255);
		gfx.PutPixel(x+5, y + 5, rg, rg, 255);
	}
	else {
		/*x line left*/
		gfx.PutPixel(x - 3, y, rg, rg, 255); /*(x,y,color(r,g,b))*/
		gfx.PutPixel(x - 4, y, rg, rg, 255);
		gfx.PutPixel(x - 5, y, rg, rg, 255);

		gfx.PutPixel(x + 3, y, rg, rg, 255);
		gfx.PutPixel(x + 4, y, rg, rg, 255);
		gfx.PutPixel(x + 5, y, rg, rg, 255);

		gfx.PutPixel(x, y - 3, rg, rg, 255);
		gfx.PutPixel(x, y - 4, rg, rg, 255);
		gfx.PutPixel(x, y - 5, rg, rg, 255);

		gfx.PutPixel(x, y + 3, rg, rg, 255);
		gfx.PutPixel(x, y + 5, rg, rg, 255);
		gfx.PutPixel(x, y + 4, rg, rg, 255);

	}
	
	

	
	
	
}
