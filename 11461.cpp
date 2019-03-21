//#include <bits/stdc++>
#include <iostream>

using namespace std;

int main(){
//	cin.tie(0); ios_base::sync_with_stdio(false);
	long long int a, b;
	while( cin >> a >> b && (a && b)){
		long long cnt = 0;
		for(long long i = 1; (i*i) <= b; i++){
			if((i*i) <= b && (i*i) >= a){
				cnt++;
			}
	
		}
		cout << cnt << '\n';
	}
	return 0;
}
