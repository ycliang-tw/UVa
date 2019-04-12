#include <iostream>
#include <string>
using namespace std;

int main(){
	string str;
	while(getline(cin, str)){
		for(int i = 0; i < str.length(); i++){
			int num = 0;
			while(isdigit(str[i]))	num += (int)(str[i] - '0'), i++;
			if(str[i] == '!')	cout << '\n';
			else if(str[i] == 'b'){
				while(num--)	cout << ' ';
			}else{
				while(num--)	cout << str[i];
			}
		}
		cout << '\n';
	}
	return 0;
}
