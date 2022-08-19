#include <iostream>
#include <windows.h>
using namespace std;

int height = 20;
int width = 20;
int enemyX[5];
int enemyY[5];
int enemyCounter;
int enemyNumber = 0;
int enemyNumber2 = 1;
bool gameOver = false;

void draw() {
	system("cls");

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)	cout << "#";
			else if (enemyX[0] == j && enemyY[0] ==i || enemyX[1] == j && enemyY[1] == i) cout << "*";
			// else if () cout << "*";
			// else if (enemyX[1] == i && enemyY[1] == j) cout << "*";
			// else if (enemyX[2] == i && enemyY[2] == j) cout << "*";
			// else if (enemyX[3] == i && enemyY[3] == j) cout << "*";
			// else if (enemyX[4] == i && enemyY[4] == j) cout << "*";
			else cout << " ";
		}
		cout << "\n";
	}
	enemyY[0]++;
	enemyY[1]++;
	cout << enemyY[0];
	cout << " ";
	cout << enemyY[1];
}

void logic() {
	
	if (enemyCounter == 10) {
		enemyX[enemyNumber2] = rand() % width;
		enemyY[enemyNumber2++] = 1;
		if (enemyNumber2>2) enemyNumber2 = 0;
	} 
	
	if (enemyCounter == 20)
	{
		enemyY[enemyNumber++]=1;
		enemyCounter = 0;
		if (enemyNumber>2) enemyNumber = 0;
	}

}

void setup() {
	enemyX[0] = rand() % width;
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