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
int score;
int enemyNumber = 0;
int enemyNumber2 = 0;
bool gameOver = false;
enum Dir {STOP = 0, LEFT, RIGHT};
Dir dir;


void logoDoller() {
    system("cls");

    for(int p = 0; p < 20; p++) {
		for(int q = 0; q<25; q++) {
			if(p<18 && p>1 && (q==11 || q==12 || q==13))    cout<<" ";
            else if(p==6 && q<20 && 5<=q) cout<<" ";
            else if((p==7 && (q==4 || q==5))||
                    (p==8 && (q==3 || q==4))||
                    (p==9 && (q==4 || q==5))||
                    (p==10 && q<20 && 5<=q)||
                    (p==11 && (q==19 || q==20))||
                    (p==12 && (q==20 || q==21))||
                    (p==13 && (q==19 || q==20))) cout<<" ";
            else if(p==14 && q<20 && 5<=q) cout<<" ";
			else cout<<"#";
		}
		cout<<"\n";
	}
}

void setup() {
	// logoDoller();
    // Sleep(10000);
	carX = width/2;
    carY = height-2;
	score = 0;
}

void draw() {
	system("cls");

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)	cout << "#";
			else if (enemyX[0] == j && enemyY[0] == i) cout << "$";
			else if (enemyX[1] == j && enemyY[1] == i) cout << "$";
			else if (enemyX[2] == j && enemyY[2] == i) cout << "$";
			else if (enemyX[3] == j && enemyY[3] == i) cout << "$";
			else if (enemyX[4] == j && enemyY[4] == i) cout << "$";
			else if (i == carY && j == carX)    cout << "U";
			else cout << " ";
		}
		cout << "\n";
	}
// 	used to change the doller position
	enemyY[0]++;
	enemyY[1]++;
	enemyY[2]++;
	enemyY[3]++;
	enemyY[4]++;

	if ((enemyY[0] == 19 && carX == enemyX[0]) || 
				(enemyY[1] == 19 && carX == enemyX[1]) ||
				(enemyY[2] == 19 && carX == enemyX[2]) ||
				(enemyY[3] == 19 && carX == enemyX[3]) ||
				(enemyY[4] == 19 && carX == enemyX[4])
				) score++;

	cout<<score;
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