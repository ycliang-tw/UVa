#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
	int ncase;
	while(cin >> ncase){
		vector<long long>cost(36, 0);
		for(int id = 1; id <= ncase; id++){
			cout << "Case " << id << ":\n";
			for(int i = 0; i < 36; i++){
				cin >> cost[i];
			}
			int nnum = 0;
			cin >> nnum;
			while(nnum--){
				long long num;
				map<long long, vector<int>>cheap_base;
				long long cheapest = 0x7fffffff;
				cin >> num;
				for(int base = 2; base <= 36; base++){
					long long val = 0, tmp = num;
					while(tmp){								// num == 0 will not be calculated, but it seems fine
						int idx = tmp%base;
						val += cost[idx];
						tmp /= base;
					}
//					cout << "num, base, val: " << num << ", " << base << ", " << val << '\n';
					if(val <= cheapest){
						cheapest = val;
						auto iter = cheap_base.find(cheapest);
						if(iter != cheap_base.end()){
							iter->second.push_back(base);
						}else{
							cheap_base[cheapest].push_back(base);
						}

					}

				}
				cout << "Cheapest base(s) for number " << num << ":";
				for(int it = 0; it < cheap_base[cheapest].size(); it++){
					cout << " " << cheap_base[cheapest][it];
				}
				cout << '\n';
			}
			if(id != ncase) cout << '\n';

		}
	}
	return 0;
}
