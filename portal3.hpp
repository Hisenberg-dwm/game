#pragma once
#include <math.h>
#include <stdlib.h>

extern double playerX;
extern double playerY;
extern int gameState;

const int PORTAL3_ROWS = 25;
const int PORTAL3_COLS = 25;
const int PORTAL3_TILE = 40;

// Tile Key:
// 0 = Path (Obsidian Floor)
// 1 = Reinforced Metal Barrier
// 2 = Magma Basin (Wall / Solid Obstacle)
// 3 = Crystal Goal
// 4 = Spike Hazard (Solid Obstacle)
// 5 = Speed Boost Pad (Interactive Tile)
int portal3Map[PORTAL3_ROWS][PORTAL3_COLS] = {
	{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
	{ 2, 0, 4, 4, 0, 0, 1, 1, 0, 0, 2, 2, 0, 2, 2, 0, 0, 1, 1, 0, 0, 4, 4, 0, 2 },
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
	{ 2, 0, 5, 0, 0, 2, 2, 0, 0, 4, 4, 0, 0, 0, 4, 4, 0, 0, 2, 2, 0, 0, 5, 0, 2 },
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
	{ 2, 1, 1, 0, 0, 4, 0, 0, 2, 2, 0, 0, 1, 0, 0, 2, 2, 0, 0, 4, 0, 0, 1, 1, 2 },
	{ 2, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 2 },
	{ 2, 0, 2, 2, 0, 0, 0, 1, 1, 0, 0, 5, 0, 5, 0, 0, 1, 1, 0, 0, 0, 2, 2, 0, 2 },
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
	{ 2, 0, 4, 0, 0, 1, 1, 0, 0, 2, 2, 0, 0, 0, 2, 2, 0, 0, 1, 1, 0, 0, 4, 0, 2 },
	{ 2, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 2 },
	{ 2, 0, 0, 0, 0, 2, 2, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 2, 2, 0, 0, 0, 0, 2 },
	{ 2, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 2 },
	{ 2, 0, 0, 0, 1, 1, 0, 0, 4, 4, 0, 0, 0, 0, 0, 4, 4, 0, 0, 1, 1, 0, 0, 0, 2 },
	{ 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2 },
	{ 2, 0, 2, 0, 0, 4, 4, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 4, 4, 0, 0, 2, 0, 2 },
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
	{ 2, 1, 1, 0, 0, 0, 0, 2, 2, 0, 0, 5, 0, 5, 0, 0, 2, 2, 0, 0, 0, 0, 1, 1, 2 },
	{ 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 2 },
	{ 2, 0, 4, 4, 0, 1, 0, 0, 0, 4, 4, 0, 0, 0, 4, 4, 0, 0, 0, 1, 0, 4, 4, 0, 2 },
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
	{ 2, 0, 5, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 5, 0, 2 },
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
	{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 }
};

inline bool isPortal3Solid(double x, double y) {
	int col = (int)(x / PORTAL3_TILE);
	int row = PORTAL3_ROWS - 1 - (int)(y / PORTAL3_TILE);

	if (row < 0 || row >= PORTAL3_ROWS || col < 0 || col >= PORTAL3_COLS) return true;

	int tile = portal3Map[row][col];
	// Solid obstacles: Metal Barriers (1), Magma Basins (2), Spike Hazards (4)
	return (tile == 1 || tile == 2 || tile == 4);
}

inline void updatePortal3Mechanics() {
	if (gameState != 7) return; // Assuming gameState 7 is set for Portal 3

	int col = (int)(playerX / PORTAL3_TILE);
	int row = PORTAL3_ROWS - 1 - (int)(playerY / PORTAL3_TILE);

	if (row >= 0 && row < PORTAL3_ROWS && col >= 0 && col < PORTAL3_COLS) {
		// Speed Boost Pad Interaction
		if (portal3Map[row][col] == 5) {
			playerY += 12.0; // Launches the player forward through passages
		}
	}
}

void drawPortal3Map() {
	for (int row = 0; row < PORTAL3_ROWS; row++) {
		for (int col = 0; col < PORTAL3_COLS; col++) {
			int x = col * PORTAL3_TILE;
			int y = (PORTAL3_ROWS - 1 - row) * PORTAL3_TILE;

			// Floor Palette: Dark Charcoal & Deep Obsidian Checker Pattern
			if ((row + col) % 2 == 0) iSetColor(30, 32, 40);
			else iSetColor(45, 48, 58);

			iFilledRectangle(x, y, PORTAL3_TILE, PORTAL3_TILE);

			int tileType = portal3Map[row][col];

			if (tileType == 1) { // Reinforced Metal Barrier
				iSetColor(80, 90, 100);
				iFilledRectangle(x + 2, y + 2, 36, 36);
				iSetColor(220, 120, 0); // Orange Rivet Trim
				iRectangle(x + 5, y + 5, 30, 30);
			}
			else if (tileType == 2) { // Magma Basin
				iSetColor(180, 40, 0);
				iFilledRectangle(x, y, PORTAL3_TILE, PORTAL3_TILE);
				iSetColor(255, 140, 0);
				iFilledEllipse(x + 20, y + 20, 14, 10);
				iSetColor(255, 215, 0);
				iFilledEllipse(x + 20, y + 20, 8, 5);
			}
			else if (tileType == 3) { // Basic Crystal Goal
				double dx = (double)x;
				double dy = (double)y;

				iSetColor(139, 0, 0);
				double outerX[] = { dx + 20.0, dx + 32.0, dx + 20.0, dx + 8.0 };
				double outerY[] = { dy + 35.0, dy + 20.0, dy + 5.0, dy + 20.0 };
				iFilledPolygon(outerX, outerY, 4);

				iSetColor(255, 50, 50);
				double innerX[] = { dx + 20.0, dx + 26.0, dx + 20.0, dx + 14.0 };
				double innerY[] = { dy + 29.0, dy + 20.0, dy + 11.0, dy + 20.0 };
				iFilledPolygon(innerX, innerY, 4);
			}
			else if (tileType == 4) { // Spike Hazard
				iSetColor(110, 115, 125);
				iFilledRectangle(x + 4, y + 4, 32, 32);
				iSetColor(200, 200, 210);

				// Render 4 Spikes
				double s1X[] = { (double)x + 10, (double)x + 15, (double)x + 20 };
				double s1Y[] = { (double)y + 6, (double)y + 34, (double)y + 6 };
				iFilledPolygon(s1X, s1Y, 3);

				double s2X[] = { (double)x + 20, (double)x + 25, (double)x + 30 };
				double s2Y[] = { (double)y + 6, (double)y + 34, (double)y + 6 };
				iFilledPolygon(s2X, s2Y, 3);
			}
			else if (tileType == 5) { // Cyan Speed Boost Pad
				iSetColor(0, 180, 216);
				iFilledRectangle(x + 4, y + 4, 32, 32);
				iSetColor(255, 255, 255);

				// Forward Arrow Indicator
				double arrowX[] = { (double)x + 20, (double)x + 30, (double)x + 10 };
				double arrowY[] = { (double)y + 30, (double)y + 10, (double)y + 10 };
				iFilledPolygon(arrowX, arrowY, 3);
			}
		}
	}
}