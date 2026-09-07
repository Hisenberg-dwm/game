#include "iGraphics.h"

int gameState = 0;
int menuBgImage;
int playerHealth = 6;

#include "Menu.hpp"
#include "Portal.hpp"
#include "Mainmap.hpp"
#include "Character.hpp"
#include "portal2.hpp"
#include "portal3.hpp"


void iDraw() {
	iClear();

	if (gameState == 0) drawMenuScreen();
	else if (gameState == 2) {
		if (appState == APP_MAP) {
			currentLevel.draw();
			drawPlayer();

			// Interaction hint for Puzzle
			if (isNearPuzzle(playerX, playerY)) {
				iSetColor(255, 255, 255);
				iText(playerX - 60, playerY + 50, "Press [F] to solve Puzzle", GLUT_BITMAP_HELVETICA_18);
			}

			// Interaction hint for Portal 1 (Top-Left)
			if (isPortalOpen && playerX < 200 && playerY > 700) {
				iSetColor(255, 255, 255);
				iText(playerX - 60, playerY + 70, "Press [G] to enter Portal 1", GLUT_BITMAP_HELVETICA_18);
			}

			// Interaction hint for Portal 2 (Top-Right)
			if (playerX > 800 && playerY > 700) {
				iSetColor(255, 255, 255);
				iText(playerX - 60, playerY + 70, "Press [H] to enter Portal 2", GLUT_BITMAP_HELVETICA_18);
			}

			// Interaction hint for Portal 3 (Near Big Tree)
			if (isNearBigTree(playerX, playerY)) {
				iSetColor(255, 255, 255);
				iText(playerX - 60, playerY + 70, "Press [J] to enter Portal 3", GLUT_BITMAP_HELVETICA_18);
			}
		}
		else if (appState == APP_PUZZLE) {
			drawPuzzleMinigame();
		}
	}
	else if (gameState == 3) drawStoryPopup();
	else if (gameState == 4) drawCreditsPopup();
	else if (gameState == 5) {
		drawPortal1Map();
		drawPlayer();
	}
	else if (gameState == 6) {
		// Draw Level from portal2.hpp
		drawPortal2Map();
		drawPlayer();
	}
	else if (gameState == 7) {
		// Draw Level from portal3.hpp
		drawPortal3Map();
		drawPlayer();
	}
	if (gameState == 2 || gameState == 5 || gameState == 6 || gameState == 7) {
		drawHealthUI();
	}
}

void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

		// 1. MAIN MENU BUTTONS
		if (gameState == 0) {
			for (int i = 0; i < 4; i++) {

				if (mx >= menuBtns[i].x && mx <= (menuBtns[i].x + menuBtns[i].width) &&
					my >= menuBtns[i].y && my <= (menuBtns[i].y + menuBtns[i].height)) {

					if (i == 0) gameState = 2;       // ENTER GAME
					else if (i == 1) gameState = 3;  // STORY
					else if (i == 2) gameState = 4;  // CREDITS
					else if (i == 3) exit(0);        // EXIT
					break;
				}
			}
		}

		// 2. PUZZLE MINIGAME BOXES
		else if (gameState == 2 && appState == APP_PUZZLE) {
			for (int i = 0; i < NUM_BOXES; i++) {

				bool insideX = (mx >= boxes[i].x && mx <= (boxes[i].x + BOX_SIZE));
				bool insideY = (my >= boxes[i].y && my <= (boxes[i].y + BOX_SIZE));

				if (insideX && insideY) {
					if (i == correctIndex) {
						score++;
						checkGameEnd();
						if (appState == APP_PUZZLE) startNewRound();
					}
					else {
						miss++;
						checkGameEnd();
						if (appState == APP_PUZZLE) startNewRound();
					}
					break;
				}
			}
		}

		// 3. STORY POPUP 
		else if (gameState == 3) {
			if (mx < 200 || mx > 800 || my < 200 + 50 || my > 800 + 50) {
				gameState = 0;
			}
		}

		// 4. CREDITS POPUP
		else if (gameState == 4) {
			if (mx < 300 || mx > 700 || my < 300 + 50 || my > 700 + 50) {
				gameState = 0;
			}
		}
	}
}

void iKeyboard(unsigned char key) {}
void iSpecialKeyboard(unsigned char key) {}
void iMouseMove(int mx, int my) {}
void iPassiveMouseMove(int mx, int my) {}

void fixedUpdate() {
	if (gameState == 2) {
		if (appState == APP_MAP) {
			playerWalking = false;

			double moveSpeed = 1.2;
			double newX = playerX;
			double newY = playerY;

			if (isKeyPressed('w') || isKeyPressed('W') || isSpecialKeyPressed(GLUT_KEY_UP)) {
				newY += moveSpeed;
				playerDirection = 3;
				playerWalking = true;
			}
			if (isKeyPressed('s') || isKeyPressed('S') || isSpecialKeyPressed(GLUT_KEY_DOWN)) {
				newY -= moveSpeed;
				playerDirection = 0;
				playerWalking = true;
			}
			if (isKeyPressed('a') || isKeyPressed('A') || isSpecialKeyPressed(GLUT_KEY_LEFT)) {
				newX -= moveSpeed;
				playerDirection = 1;
				playerWalking = true;
			}
			if (isKeyPressed('d') || isKeyPressed('D') || isSpecialKeyPressed(GLUT_KEY_RIGHT)) {
				newX += moveSpeed;
				playerDirection = 2;
				playerWalking = true;
			}

			// Open Minigame
			if (isKeyPressed('f') || isKeyPressed('F')) {
				if (isNearPuzzle(playerX, playerY)) {
					appState = APP_PUZZLE;
					score = 0;
					miss = 0;
					startNewRound();
				}
			}

			// Enter Portal 1 (Top-Left)
			if (isPortalOpen && (isKeyPressed('g') || isKeyPressed('G'))) {
				if (playerX < 200 && playerY > 700) {
					gameState = 5;
					playerX = 500.0;
					playerY = 100.0;
				}
			}

			// Enter Portal 2 (Top-Right)
			if (isKeyPressed('h') || isKeyPressed('H')) {
				if (playerX > 800 && playerY > 700) {
					gameState = 6;
					playerX = 500.0;
					playerY = 100.0;
				}
			}

			// Enter Portal 3 (Near Big Tree)
			if (isKeyPressed('j') || isKeyPressed('J')) {
				if (isNearBigTree(playerX, playerY)) {
					gameState = 7;
					playerX = 500.0;
					playerY = 100.0;
				}
			}

			// Screen Boundary 
			if (newX < 18.0) newX = 18.0;
			if (newX > SCREEN_WIDTH - 18.0) newX = SCREEN_WIDTH - 18.0;
			if (newY < 10.0) newY = 10.0;
			if (newY > SCREEN_HEIGHT - 48.0) newY = SCREEN_HEIGHT - 48.0;

			// Collision checking
			if (!isSolid(newX, playerY)) playerX = newX;
			if (!isSolid(playerX, newY)) playerY = newY;

			if (playerWalking) {
				walkFrame += 0.08;
				if (walkFrame >= 2 * PI) walkFrame -= 2 * PI;
			}
			else {
				walkFrame = 0;
			}
		}
		else if (appState == APP_PUZZLE) {
			gameTick();
		}
	}
	else if (gameState == 5 || gameState == 6 || gameState == 7) {
		playerWalking = false;

		double moveSpeed = 1.2;
		double newX = playerX;
		double newY = playerY;

		if (isKeyPressed('w') || isKeyPressed('W') || isSpecialKeyPressed(GLUT_KEY_UP)) {
			newY += moveSpeed;
			playerDirection = 3;
			playerWalking = true;
		}
		if (isKeyPressed('s') || isKeyPressed('S') || isSpecialKeyPressed(GLUT_KEY_DOWN)) {
			newY -= moveSpeed;
			playerDirection = 0;
			playerWalking = true;
		}
		if (isKeyPressed('a') || isKeyPressed('A') || isSpecialKeyPressed(GLUT_KEY_LEFT)) {
			newX -= moveSpeed;
			playerDirection = 1;
			playerWalking = true;
		}
		if (isKeyPressed('d') || isKeyPressed('D') || isSpecialKeyPressed(GLUT_KEY_RIGHT)) {
			newX += moveSpeed;
			playerDirection = 2;
			playerWalking = true;
		}

		// Boundary Clamping
		if (newX < 18.0) newX = 18.0;
		if (newX > SCREEN_WIDTH - 18.0) newX = SCREEN_WIDTH - 18.0;
		if (newY < 10.0) newY = 10.0;
		if (newY > SCREEN_HEIGHT - 48.0) newY = SCREEN_HEIGHT - 48.0;

		// Portal Collision Checking
		if (gameState == 5) {
			if (!isPortalSolid(newX, playerY)) playerX = newX;
			if (!isPortalSolid(playerX, newY)) playerY = newY;
		}
		else if (gameState == 6) {
			if (!isPortal2Solid(newX, playerY)) playerX = newX;
			if (!isPortal2Solid(playerX, newY)) playerY = newY;
		}
		else if (gameState == 7) {
			if (!isPortal3Solid(newX, playerY)) playerX = newX;
			if (!isPortal3Solid(playerX, newY)) playerY = newY;

			// Process boost pads in Portal 3
			updatePortal3Mechanics();
		}

		if (playerWalking) {
			walkFrame += 0.08;
			if (walkFrame >= 2 * PI) walkFrame -= 2 * PI;
		}
		else {
			walkFrame = 0;
		}
	}
}

int main() {
	iInitialize(1000, 1000, "Mystic Grove");

	menuBgImage = iLoadImage("menu.png");

	setupBoxPositions();

	// Initialize Portal 1 and Portal 2 Enemies
	initPortalSlimes();
	initPortal2Drones();

	// Timers for movement and updates
	iSetTimer(16, fixedUpdate);

	// Portal 1 Slimes
	iSetTimer(15, updatePortalSlimes);
	iSetTimer(3000, shootSlimeBullets);

	// Portal 2 Drones
	iSetTimer(15, updatePortal2Drones);
	iSetTimer(3000, shootPortal2DroneBullets);

	iStart();
	return 0;
}