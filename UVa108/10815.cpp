#include <iostream>
#include <string>
#include <sstream>
#include <set>
using namespace std;

int main(){
	
	string input, buf;
	set<string> dict;

	while(cin >> input){
		for(int i = 0; i < input.length(); i++){
			if(isalpha(input[i])){
				input[i] = tolower(input[i]);
			}else{
				input[i] = ' ';
			}
		}

		stringstream ss(input);
		while(ss >> buf)
			dict.insert(buf);
	}

	for(set<string>::iterator it = dict.begin(); it != dict.end(); it++){
		cout << *it << '\n';
	}
	return 0;
}
