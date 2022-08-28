#include <iostream>
#include <windows.h>
using namespace std;

int height = 20;
int width = 25;
int dollerX[5];
int dollerY[5];
int counter;
int dollerNumber = 0;
int dollerNumber2 = 0;
bool gameOver = false;

void draw() {
	system("cls");

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)	cout << "#";
			else if (dollerX[0] == j && dollerY[0] == i) cout << "*";
			else if (dollerX[1] == j && dollerY[1] == i) cout << "*";
			else if (dollerX[2] == j && dollerY[2] == i) cout << "*";
			else if (dollerX[3] == j && dollerY[3] == i) cout << "*";
			else if (dollerX[4] == j && dollerY[4] == i) cout << "*";
			else cout << " ";
		}
		cout << "\n";
	}
	dollerY[0]++;
	dollerY[1]++;
	dollerY[2]++;
	dollerY[3]++;
	dollerY[4]++;
	cout << dollerY[0];
	cout << " ";
	cout << dollerY[1];
	cout << " ";
	cout << dollerY[2];
	cout << " ";
	cout << dollerY[3];
	cout << " ";
	cout << dollerY[4];
}

void logic() {
	
	if (counter % 10 == 0) {
		dollerX[dollerNumber] = rand() % width +1;
		dollerY[dollerNumber] = 1;
		++dollerNumber;
		if (dollerNumber>4) dollerNumber = 0;
	}
	else if (counter % 20 == 0)	{
		dollerX[dollerNumber2] = rand() % width +1;
		dollerY[dollerNumber2] = 1;
		++dollerNumber2;
		if (dollerNumber2>4) dollerNumber2 = 0;
		counter = 0;
	}


}

void setup() {
	// cout << enemyX;
}

int main() {

	setup();

	while(!gameOver)
	{
		draw();
		logic();
		counter+=1;
		Sleep(100);
	}
}