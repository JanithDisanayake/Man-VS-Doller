#include <iostream>
#include <windows.h>
using namespace std;

int height = 20;
int width = 20;
int enemyX;
int enemyY = 1;
int enemyCounter;
int enemyNumber = 0;
bool gameOver = false;

void draw() {
	system("cls");

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)	cout << "#";
			else if (enemyX == j && enemyY ==i) {
				cout << "*";
			}
			// else if (enemyX[0] == i && enemyY[0] == j) cout << "*";
			// else if (enemyX[1] == i && enemyY[1] == j) cout << "*";
			// else if (enemyX[2] == i && enemyY[2] == j) cout << "*";
			// else if (enemyX[3] == i && enemyY[3] == j) cout << "*";
			// else if (enemyX[4] == i && enemyY[4] == j) cout << "*";
			else cout << " ";
		}
		cout << "\n";
	}
	cout << enemyX;
	enemyY++;
}

void logic() {
	
	if (enemyCounter == width)
	{
		
		enemyX = rand() % 20;
		enemyY = 1;
		// enemyX[enemyNumber] = rand() % width;
		// enemyY[enemyNumber] = rand() % height;
		enemyNumber++;
		if (enemyNumber == 5) enemyNumber = 0;
		enemyCounter = 0;
	}

}

void setup() {
	enemyX = rand() % width + 1;
	cout << enemyX;
}

int main() {

	setup();

	while(!gameOver)
	{
		draw();
		logic();
		enemyCounter++;
		Sleep(100);
	}
}