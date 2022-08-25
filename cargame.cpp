#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

int height = 20;
int width = 25;
int carX;
int carY;
int enemyX[5];
int enemyY[5];
int enemyCounter;
int enemyNumber = 0;
int enemyNumber2 = 0;
bool gameOver = false;
enum Dir {STOP = 0, LEFT, RIGHT};
Dir dir;


void setup() {
	carX = width/2;
    carY = height-2;
}

void draw() {
	system("cls");

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)	cout << "#";
			else if (enemyX[0] == j && enemyY[0] == i) cout << "*";
			else if (enemyX[1] == j && enemyY[1] == i) cout << "*";
			else if (enemyX[2] == j && enemyY[2] == i) cout << "*";
			else if (enemyX[3] == j && enemyY[3] == i) cout << "*";
			else if (enemyX[4] == j && enemyY[4] == i) cout << "*";
			else if (i == carY && j == carX)    cout << "M";
			else cout << " ";
		}
		cout << "\n";
	}
	enemyY[0]++;
	enemyY[1]++;
	enemyY[2]++;
	enemyY[3]++;
	enemyY[4]++;
	// cout << enemyY[0];
	// cout << " ";
	// cout << enemyY[1];
	// cout << " ";
	// cout << enemyY[2];
	// cout << " ";
	// cout << enemyY[3];
	// cout << " ";
	// cout << enemyY[4];
}

void input() {
    if(_kbhit()) {

        char type = _getch();

        if (type == 'a')
            carX--;
        else if (type == 'd')
            carX++;
        else if (carX <= 1)    
            carX = 1;
        else
            carX=carX;

        if (carX < 2)   carX=width-3;
        if (carX > width-3) carX=2;
    }
}

void logic() {
	
	if (enemyCounter % 10 == 0) {
		enemyX[enemyNumber] = rand() % width +1;
		enemyY[enemyNumber] = 1;
		++enemyNumber;
		if (enemyNumber>4) enemyNumber = 0;
	}
	else if (enemyCounter % 20 == 0)	{
		enemyX[enemyNumber2] = rand() % width +1;
		enemyY[enemyNumber2] = 1;
		++enemyNumber2;
		if (enemyNumber2>4) enemyNumber2 = 0;
		enemyCounter = 0;
	}


}

int main() {

	setup();

	while(!gameOver)
	{
		input();
		draw();
		logic();
		enemyCounter+=1;
		Sleep(100);
	}
}