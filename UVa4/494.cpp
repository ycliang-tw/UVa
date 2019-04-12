#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	string str;
	while(getline(cin, str)){
		long long cnt = 0;
		for(int i = 0; str[i]; i++){
			if(isalpha(str[i])){
				cnt++;
				while(isalpha(str[i]))	i++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
