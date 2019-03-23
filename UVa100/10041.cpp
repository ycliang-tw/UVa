#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(){
	int ncase;
	cin >> ncase;
	while(ncase--){
		int len;
		cin >> len;
		vector<int>arr(len);
		for(int i = 0; i < len; i++){
			cin >> arr[i];
		}
		sort(arr.begin(), arr.begin()+len);
		int odd = len & 1, live, ans = 0;
		if(odd){
			live = arr[len/2];
		}else{
			live = arr[len/2-1];
		}
		for(int i = 0; i < len; i++){
			ans += abs(live - arr[i]);
		}
		cout << ans << '\n';
	}
	return 0;
}
