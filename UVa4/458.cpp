#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;
	while(cin >> input){
		for(int i = 0; i < input.length(); i++){
			cout << (char)(input[i] + ('*' - '1'));
		}
		cout << '\n';
	}
	return 0;
}
