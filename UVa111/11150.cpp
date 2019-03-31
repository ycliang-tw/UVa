#include <iostream>
using namespace std;

int main(){
	int bottle;
	while( cin >> bottle ){
		int cnt = bottle;
		while(bottle >= 3) {
			cnt += (bottle/3);
			bottle = bottle%3 + bottle/3;
		}
		if(bottle == 2) cout << cnt + 1 << '\n';
		else cout << cnt << '\n';
	}
	return 0;
}
