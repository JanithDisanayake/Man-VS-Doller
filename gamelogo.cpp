#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

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

int main() {

	logoDoller();
    Sleep(10000);
    system("cls");
}