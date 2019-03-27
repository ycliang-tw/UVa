#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	int ncase;
	while( cin >> ncase ){
		while(ncase--){
			int m, n, npairs;
			while( cin >> m >> n >> npairs ){
				cout << m << " " << n  << " " << npairs << '\n';
				string input;
				vector<string>table;
				for(int i = 0; i < m; i++){
					cin >> input;
					table.push_back(input);
				}
				for(int i = 0; i < npairs; i++){
					int x, y, ans = 1;
					cin >> x >> y;
					int idx;
					for(idx = 1; idx < m || idx < n; idx++){
						int flag = 0;
						for(int a = x-idx; a <= x+idx; a++){
							for(int b = y-idx; b <= y+idx; b++){
								if(a < 0 || a >= m || b < 0 || b >= n){
									flag = 1;
									break;
								}
								if(table[a][b] != table[x][y]){
									flag = 1;
									break;
								}
							}
						}
						if(flag == 0)
							ans = idx*2+1;
						else 
							break;
					}
					cout << ans << '\n';
				}
			}
		}
	}
	return 0;
}
