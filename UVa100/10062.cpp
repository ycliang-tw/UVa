#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct bind{
	char c;
	int n = 0;
};
bool comp(struct bind a, struct bind b){
	if(a.n == b.n){
		return (int)a.c > (int)b.c;
	}
	return a.n < b.n;
}

int main(){
	string input;
	int i = 0;
	while( getline(cin, input) ){
		vector<struct bind>arr(130);
		for(int i = 0; i < input.length(); i++){
			arr[ input[i] ].n++;
			arr[ input[i] ].c = input[i];
		}
		sort(arr.begin(), arr.end(), comp);
		if(i != 0) cout << '\n';
		for(int i = 0; i < arr.size(); i++){
			if(arr[i].n != 0){
				cout << (int)arr[i].c << " " << arr[i].n << '\n';
			}
		}
		i++;
	}
	return 0;
}
