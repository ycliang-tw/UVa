#include <iostream>
#include <vector>
using namespace std;

int main(){
	long long input;
	while(cin >> input && input){
		int cnt = 0;
		vector<bool>bin;
		while(input){
			if(input & 1){
				cnt++;
				bin.push_back(true);
			}else{
				bin.push_back(false);
			}
			input = input >> 1;
		}
		cout << "The parity of ";
		for(auto i = bin.rbegin(); i != bin.rend(); i++){
			if((*i))
				cout << "1";
			else
				cout << "0";
		}
		cout << " is " << cnt << " (mod 2).\n";
		
	}
	return 0;
}
