#include <iostream>
#include <vector>
using namespace std;

int main(){
	int ncase;
	while(cin >> ncase){
		while(ncase--){
			int days, nparties, cnt = 0;
			cin >> days >> nparties;
//			vector<bool>ans(false, days+10);
			bool ans[10000] = {};
			while(nparties--){
				int hartals;
				cin >> hartals;
				int tmp = hartals;
				while(tmp <= days){
					if( ((tmp-6) % 7 != 0) && (tmp % 7 != 0) ){
//						cout << "hartals == " << tmp << '\n';
						ans[tmp] = true;
					}
					tmp += hartals;
				}
			}
			for(int i = 1; i <= days; i++){
				if( ans[i] == true )
					cnt++;
			}
			cout << cnt << '\n';
		}
	}
	return 0;
}
