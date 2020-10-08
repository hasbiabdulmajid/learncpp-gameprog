#pragma once

class Item {
public:
	void Update();

	int x;
	int y;
	int vx;
	int vy;
	int width = 24;
	int height = 24;

	bool isPicked = false;
};