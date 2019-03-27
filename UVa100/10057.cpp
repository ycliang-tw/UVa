#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int nnum;
	while( cin >> nnum ){
		vector<int>arr;
		for(int i = 0; i < nnum; i++){
			int num;
			cin >> num;
			arr.push_back(num);
		}
		sort(arr.begin(), arr.end());
		if( arr.size() % 2 != 0 ){
			cout << arr[ arr.size()/2 ] << " ";
			int cnt = 0;
			for(int j = 0; j < arr.size(); j++){
				if(arr[j] == arr[ arr.size()/2 ])
					cnt++;
			}
			cout << cnt << " 1\n";
		}else{
			cout << arr[ arr.size()/2 -1 ] << " ";
			int cnt = 0, n = arr[ arr.size()/2 ];
			for(int j = 0; j < arr.size(); j++){
				if(arr[j] == arr[ arr.size()/2 -1 ] || arr[j] == arr[ arr.size()/2 ])
					cnt++;
			}
			cout << cnt << " " << n-arr[ arr.size()/2 -1] + 1 << "\n";
		}
	}
	return 0;
}
