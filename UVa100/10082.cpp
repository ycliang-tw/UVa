#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(){
	string shift = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	char c;
	while((c = getchar()) != EOF){
		int i = shift.find(c);
		if(i != string::npos)	cout << shift[i-1];
		else 					cout << c;
	}
	return 0;
}
