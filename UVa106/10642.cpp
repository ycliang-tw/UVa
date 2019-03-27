#include <iostream>
using namespace std;

int main(){
	int ncase;
	while(cin >> ncase){
		for(int i = 1; i <= ncase; i++){
			long long int srcx, srcy, desx, desy;
			cin >> srcx >> srcy >> desx >> desy;
			long long int srcid = (srcx+srcy+3) * (srcx+srcy) / 2 - srcy;
			long long int desid = (desx+desy+3) * (desx+desy) / 2 - desy;
			cout << "Case " << i << ": " << desid - srcid << '\n';
		}
	}
	return 0;
}
