#pragma once
#include <math.h> 


extern double playerX;
extern double playerY;
extern int gameState;

const int PORTAL_ROWS = 25;
const int PORTAL_COLS = 25;
const int PORTAL_TILE = 40;

//  0 = Path, 1 = Stone, 2 = Bush, 3 = Crystal
int portalMap[PORTAL_ROWS][PORTAL_COLS] = {
	{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
	{ 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2 },
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
	{ 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
	{ 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2 },
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
	{ 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2 },
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
	{ 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2 },
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
	{ 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2 },
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
	{ 2, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 2 },
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
	{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 }
};


inline bool isPortalSolid(double x, double y) {
	int col = (int)(x / PORTAL_TILE);
	int row = PORTAL_ROWS - 1 - (int)(y / PORTAL_TILE);

	if (row < 0 || row >= PORTAL_ROWS || col < 0 || col >= PORTAL_COLS) return true;

	int tile = portalMap[row][col];
	return (tile == 1 || tile == 2);
}

const int NUM_SLIMES = 5;

struct Slime {
	double x, y;
	double speed;
	int direction;
	double bulletX, bulletY;
	int bulletActive;
};

Slime slimes[NUM_SLIMES];

void initPortalSlimes() {
	slimes[0] = { 120.0, (double)((PORTAL_ROWS - 1 - 2) * PORTAL_TILE), 2.0, 1, 0.0, 0.0, 0 };
	slimes[1] = { 520.0, (double)((PORTAL_ROWS - 1 - 7) * PORTAL_TILE), 3.0, -1, 0.0, 0.0, 0 };
	slimes[2] = { 320.0, (double)((PORTAL_ROWS - 1 - 14) * PORTAL_TILE), 1.5, 1, 0.0, 0.0, 0 };
	slimes[3] = { 280.0, (double)((PORTAL_ROWS - 1 - 17) * PORTAL_TILE), 2.5, 1, 0.0, 0.0, 0 };
	slimes[4] = { 640.0, (double)((PORTAL_ROWS - 1 - 5) * PORTAL_TILE), 2.0, -1, 0.0, 0.0, 0 };
}
void shootSlimeBullets() {
	for (int i = 0; i < NUM_SLIMES; i++) {
		if (slimes[i].bulletActive == 0) {
			slimes[i].bulletActive = 1;
			slimes[i].bulletX = slimes[i].x + (PORTAL_TILE / 2);
			slimes[i].bulletY = slimes[i].y + (PORTAL_TILE / 2);
		}
	}
}

void updatePortalSlimes() {
	for (int i = 0; i < NUM_SLIMES; i++) {


		double nextX = slimes[i].x + (slimes[i].speed * slimes[i].direction);

		if (isPortalSolid(nextX, slimes[i].y + 20) || isPortalSolid(nextX + 30, slimes[i].y + 20)) {
			slimes[i].direction *= -1;
		}
		else {
			slimes[i].x = nextX;
		}


		if (slimes[i].bulletActive == 1) {
			slimes[i].bulletY -= 5.0;

			if (slimes[i].bulletY < 0 || isPortalSolid(slimes[i].bulletX, slimes[i].bulletY)) {
				slimes[i].bulletActive = 0;
			}
		}

		// STATE CHECK
		if (gameState == 5) {
			// 3. Player Hit  
			if ((playerX - 12.0 < slimes[i].x + 36.0) &&
				(playerX + 12.0 > slimes[i].x + 4.0) &&
				(playerY < slimes[i].y + 32.0) &&
				(playerY + 50.0 > slimes[i].y + 8.0)) {

				playerHealth -= 1;
				if (playerHealth <= 0) {
					gameState = 0;
					playerHealth = 6;
				}
				playerX = 500.0;
				playerY = 60.0;
			}

			// 4. Bullet Hit  
			if (slimes[i].bulletActive == 1) {
				if ((playerX - 12.0 < slimes[i].bulletX + 8.0) &&
					(playerX + 12.0 > slimes[i].bulletX) &&
					(playerY < slimes[i].bulletY + 8.0) &&
					(playerY + 50.0 > slimes[i].bulletY)) {

					playerHealth -= 1;
					if (playerHealth <= 0) {
						gameState = 0;
						playerHealth = 6;
					}
					playerX = 500.0;
					playerY = 60.0;
					slimes[i].bulletActive = 0;
				}
			}
		}
	}
}

void drawPortalSlimes() {
	for (int i = 0; i < NUM_SLIMES; i++) {
		double sx = slimes[i].x;
		double sy = slimes[i].y;

		iSetColor(128, 0, 128);
		iFilledEllipse(sx + 20, sy + 20, 16, 12);
		iSetColor(0, 0, 0);
		iEllipse(sx + 20, sy + 20, 16, 12);

		iSetColor(255, 255, 255);
		iFilledEllipse(sx + 14, sy + 22, 3, 3);
		iFilledEllipse(sx + 26, sy + 22, 3, 3);
		iSetColor(0, 0, 0);
		iEllipse(sx + 14, sy + 22, 3, 3);
		iEllipse(sx + 26, sy + 22, 3, 3);

		if (slimes[i].bulletActive == 1) {
			iSetColor(128, 0, 128);
			iFilledRectangle(slimes[i].bulletX, slimes[i].bulletY, 8, 8);
		}
	}
}

void drawPortal1Map() {
	for (int row = 0; row < PORTAL_ROWS; row++) {
		for (int col = 0; col < PORTAL_COLS; col++) {
			int x = col * PORTAL_TILE;
			int y = (PORTAL_ROWS - 1 - row) * PORTAL_TILE;

			if ((row + col) % 2 == 0) iSetColor(34, 139, 34);
			else iSetColor(50, 205, 50);

			iFilledRectangle(x, y, PORTAL_TILE, PORTAL_TILE);

			int tileType = portalMap[row][col];

			if (tileType == 1) {
				iSetColor(105, 105, 105);
				iFilledEllipse(x + 20, y + 16, 16, 10);
				iSetColor(169, 169, 169);
				iFilledEllipse(x + 20, y + 18, 12, 6);
			}
			else if (tileType == 2) {
				iSetColor(0, 100, 0);
				iFilledEllipse(x + 20, y + 20, 20, 16);
				iSetColor(34, 139, 34);
				iFilledEllipse(x + 20, y + 24, 16, 14);
				iSetColor(107, 142, 35);
				iFilledEllipse(x + 20, y + 28, 10, 10);
			}
			else if (tileType == 3) {
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
		}
	}
	drawPortalSlimes();
}