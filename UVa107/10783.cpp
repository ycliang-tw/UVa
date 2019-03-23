#include <iostream>
using namespace std;

int main(){
	int a, b, ncase;
	while(cin >> ncase){
		int i;
		for(i = 1; i <= ncase; i++){
			cin >> a >> b;
			a = (a % 2 == 0)? a+1 : a;
			b = (b % 2 == 0)? b-1 : b;
			int cnt = (b - a)/2 + 1; 
			cout << "Case " << i << ": " << (a+b) * cnt / 2 << '\n';
		}
	}
	return 0;
}
