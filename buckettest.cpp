#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

int height = 20;
int width = 25;
int bucketX;
int bucketY;
int dollerX[5];
int dollerY[5];
int counter;
int dollerNumber = 0;
int dollerNumber2 = 0;
bool gameOver = false;
enum Dir {STOP = 0, LEFT, RIGHT};
Dir dir;

void setup() {
	bucketX = width/2;
    bucketY = height-2;
}

void draw() {
	system("cls");

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)	cout << "#";
            else if (i == bucketY && j == bucketX)    cout << "M";
			else cout << " ";
		}
		cout << "\n";
	}
    cout << counter;
}

void input() {
    if(_kbhit()) {

        char type = _getch();

        if (type == 'a')
            bucketX--;
        else if (type == 'd')
            bucketX++;
        else if (bucketX <= 1)    
            bucketX = 1;
        else
            bucketX=bucketX;

        if (bucketX < 2)   bucketX=width-3;
        if (bucketX > width-3) bucketX=2;
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
		counter+=1;
		Sleep(100);
	}
}