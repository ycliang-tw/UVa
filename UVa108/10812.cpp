#include <iostream>
using namespace std;

int main(){
	unsigned long long ncase;
	while(cin >> ncase){
		while(ncase--){
			unsigned long long x, y;
			cin >> x >> y;
			if(y > x || (x+y) % 2 != 0) cout << "impossible\n";
			else	cout << (x+y)/2 << " " << (x-y)/2 << '\n';
		}
	}
	return 0;
}
