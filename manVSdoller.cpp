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
int score;
int lifecounter = 4;
int dollerNumber = 0;
int dollerNumber2 = 0;
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
	logoDoller();
    Sleep(5000);
	bucketX = width/2;
    bucketY = height-2;
	score = 0;
	// failcounter=0;
}

void draw() {
	system("cls");

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)	cout << "#";
			else if (dollerX[0] == j && dollerY[0] == i) cout << "$";
			else if (dollerX[1] == j && dollerY[1] == i) cout << "$";
			else if (dollerX[2] == j && dollerY[2] == i) cout << "$";
			else if (dollerX[3] == j && dollerY[3] == i) cout << "$";
			else if (dollerX[4] == j && dollerY[4] == i) cout << "$";
			else if (i == bucketY && j == bucketX)    cout << "U";
			else cout << " ";
		}
		cout << "\n";
	}
// 	used to change the doller position
	dollerY[0]++;
	dollerY[1]++;
	dollerY[2]++;
	dollerY[3]++;
	dollerY[4]++;

// 	used to calculate score
	if ((dollerY[0] == 19 && bucketX == dollerX[0]) || 
				(dollerY[1] == 19 && bucketX == dollerX[1]) ||
				(dollerY[2] == 19 && bucketX == dollerX[2]) ||
				(dollerY[3] == 19 && bucketX == dollerX[3]) ||
				(dollerY[4] == 19 && bucketX == dollerX[4])
				) 
				{
					score++;
					if(lifecounter<4) lifecounter++;
				}
//	used to count missing dollers
	else if ((dollerY[0] == 19 && bucketX == dollerX[0]) || 
				(dollerY[1] == 19 && bucketX != dollerX[1]) ||
				(dollerY[2] == 19 && bucketX != dollerX[2]) ||
				(dollerY[3] == 19 && bucketX != dollerX[3]) ||
				(dollerY[4] == 19 && bucketX != dollerX[4])
				) 
				{
					lifecounter--;
					// if user fail to grab more than 3 dollers one after another he/she will fail
					if(lifecounter==0)	gameOver=true;
				}

// 	used to print the scorea
	cout<< "Score : ";
	cout<<score;
	cout<<"\n";
	cout<< "Life :  ";
	cout<< lifecounter;
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
            bucketX--;
        else if (type == 'd')
            bucketX++;
		else if (type == 'x')
			gameOver=true;
        else if (bucketX <= 1)    
            bucketX = 1;
        else
            bucketX=bucketX;

        if (bucketX < 1)   bucketX=width-2;
        if (bucketX > width-2) bucketX=1;
    }
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
	draw();
	Sleep(5000);
}