#include <iostream>
using namespace std;

int main(){
	int ncase;
	long long int fib[51] = {};
	fib[0] = 1, fib[1] = 1;
	for(int i = 2; i < 50; i++){
		fib[i] = fib[i-2] + fib[i-1];
//		cout << i << " " << fib[i] << '\n';
	}
	while(cin >> ncase){
		int input;
		while(ncase--){
			int flag = 0;
			cin >> input;
			cout << input << " = ";
			for(int i = 45; i >= 1; i--){
				if(input >= fib[i]){
					flag = 1;
				}
				if(flag){
					int tmp = input / fib[i];
					cout << tmp;
					input = input%fib[i];
				}
			}
			cout << " (fib)\n";
		}
	}
	return 0;
}
