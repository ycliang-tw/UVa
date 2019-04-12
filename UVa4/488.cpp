#include <iostream>
using namespace std;

int main(){
	int ncase, amp, freq;
	while(cin >> ncase){
		for(int x = 0; x < ncase; x++){
			if(x != 0)	cout << '\n';
			cin >> amp >> freq;
			for(int i = 0; i < freq; i++){
				if(i != 0)	cout << '\n';
				for(int j = 1; j < amp; j++){
					for(int k = 0; k < j; k++){
						cout << j;
					}
					cout << '\n';
				}
				for(int j = amp; j >= 1; j--){
					for(int k = 0; k < j; k++){
						cout << j;
					}
					cout << '\n';
				}
			}
		}
	}
	return 0;
}
