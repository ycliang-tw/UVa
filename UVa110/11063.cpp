//#include <bits/stdc++>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

int main(){
	int alen, ncase = 1;;
	while(cin >> alen){
		string input;
		bool b2flag = true;
		getline(cin, input);
		getline(cin, input);
		stringstream ss;
		ss << input;
		vector<int>arr(105, 0);
		map<int, bool>lut;
		for(int i = 0; i < alen; i++){
			ss >> arr[i];
			if(arr[i] == 0){
				b2flag = false;
			}
		}
		for(int i = 0; i < alen; i++){
			for(int j = i; j < alen; j++){
				if(arr[j] < arr[i]){
					b2flag = false;
					break;
				}
				int tmp = arr[i] + arr[j];
				auto it = lut.find(tmp);
				if(it != lut.end()){
					b2flag = false;
					break;
				}else{
					lut[tmp] = true;
				}
			}
		}
		getline(cin, input);	// blank line
		cout << "Case #" << ncase++ << ": It is ";
		if(b2flag == false)
			cout << "not ";
		cout << "a B2-Sequence.\n\n";
	}

	return 0;
}
