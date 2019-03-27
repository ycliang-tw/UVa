#include <iostream>
#include <vector>
using namespace std;

int main(){
	long long ncase;
	while( cin >> ncase ){
		while(ncase--){
			int num, cnt = 0;
			cin >> num;
			vector<int>arr(55, 0);
			for(int i = 0; i < num; i++){
				cin >> arr[i];
			}
			for(int i = 0; i < num -1; i++){
				for(int j = 0; j < num -1; j++){
					if(arr[j] > arr[j+1]){
						int tmp = arr[j];
						arr[j] = arr[j+1];
						arr[j+1] = tmp;
						cnt++;
					}
				}
			}
			cout << "Optimal train swapping takes " << cnt << " swaps.\n";
		}
	}
	return 0;
}
