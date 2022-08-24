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
            else if (i == carY && j == carX)    cout << "M";
			else cout << " ";
		}
		cout << "\n";
	}
    cout << enemyCounter;
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
	
	// if(dir==LEFT)    carX--;
    // else if (dir==RIGHT)    carX++;
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