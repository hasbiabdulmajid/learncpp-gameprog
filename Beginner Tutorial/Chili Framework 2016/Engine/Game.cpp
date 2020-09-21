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

	Boundaries();

	// Changing color specific region
	/*
	if (x > 30 && x < 150) {
		rg = 0;
	}
	else {
		rg = 255;
	} */

	if (wnd.kbd.KeyIsPressed(VK_CONTROL)) {
		rg = 0;

	}
	shapeIsChanged = wnd.kbd.KeyIsPressed(VK_SPACE);

	colliding = 
		OverlapTest(x, y, x_fixed0, y_fixed0) ||
		OverlapTest(x, y, x_fixed1, y_fixed1) ||
		OverlapTest(x, y, x_fixed2, y_fixed2) ||
		OverlapTest(x, y, x_fixed3, y_fixed3);


	

}

void Game::ComposeFrame()
{
	DrawBox(x_fixed0, y_fixed0, 100, 100, 255);
	DrawBox(x_fixed1, y_fixed1, 100, 100, 255);
	DrawBox(x_fixed2, y_fixed2, 100, 100, 255);
	DrawBox(x_fixed3, y_fixed3, 100, 100, 255);
	int r, g;

	if (colliding) {
		
		DrawBox(x, y, 255, 0, 0);
	}
	else {
		DrawBox(x, y, 255, 255, 255);
	}
	/* 
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
	} */ 
	/*
	else {
		
		gfx.PutPixel(x - 3, y, rg, rg, 255);
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

	} */
}

void Game::DrawBox(int x, int y, int r, int g, int b) {
	//upper left corner
	gfx.PutPixel(x - 3, y - 5, r, g, 255);
	gfx.PutPixel(x - 4, y - 5, r, g, 255);
	gfx.PutPixel(x - 5, y - 5, r, g, 255);
	gfx.PutPixel(x - 5, y - 4, r, g, 255);
	gfx.PutPixel(x - 5, y - 3, r, g, 255);
	//bottom left corner
	gfx.PutPixel(x - 3, y + 5, r, g, 255);
	gfx.PutPixel(x - 4, y + 5, r, g, 255);
	gfx.PutPixel(x - 5, y + 5, r, g, 255);
	gfx.PutPixel(x - 5, y + 4, r, g, 255);
	gfx.PutPixel(x - 5, y + 3, r, g, 255);
	//upper right corner
	gfx.PutPixel(x + 3, y - 5, r, g, 255);
	gfx.PutPixel(x + 4, y - 5, r, g, 255);
	gfx.PutPixel(x + 5, y - 5, r, g, 255);
	gfx.PutPixel(x + 5, y - 4, r, g, 255);
	gfx.PutPixel(x + 5, y - 3, r, g, 255);
	//bottom right corner
	gfx.PutPixel(x + 3, y + 5, r, g, 255);
	gfx.PutPixel(x + 4, y + 5, r, g, 255);
	gfx.PutPixel(x + 5, y + 5, r, g, 255);
	gfx.PutPixel(x + 5, y + 4, r, g, 255);
	gfx.PutPixel(x + 5, y + 3, r, g, 255);
}

bool Game::OverlapTest(int x, int y, int x_fixed, int y_fixed)
{
	const int left_side = x - 5;
	const int right_side = x + 5;
	const int top_side = y - 5;
	const int bottom_side = y + 5;

	const int left_sideFixed = x_fixed - 5;
	const int right_sideFixed = x_fixed + 5;
	const int top_sideFixed = y_fixed - 5;
	const int bottom_sideFixed = y_fixed + 5;

	// collide check
	return (left_side <= right_sideFixed&&
		right_side >= left_sideFixed &&
		top_side <= bottom_sideFixed&&
		bottom_side >= top_sideFixed);
		
	
}

void Game::Boundaries()
{
	const int left_side = x - 5;
	const int right_side = x + 5;
	const int top_side = y - 5;
	const int bottom_side = y + 5;

	// X Boundaries
	if (right_side >= gfx.ScreenWidth) {
		x = gfx.ScreenWidth - 6;
		vx = 0;
		vy = 0;
	} 
	else if (left_side< 0) {
		x = 5;
		vx = 0;
		vy = 0;
	}

	// Y Boundaries 
	if (bottom_side >= gfx.ScreenHeight) {
		y = gfx.ScreenHeight - 6;
		vy = 0;
		vx = 0;
	}
	else if (top_side < 0) {
		y = 5;
		vy = 0;
		vx = 0;
	}
}
