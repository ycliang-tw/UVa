#include <iostream>
#include <string>
using namespace std;

string reverse("A   3  HIL JM O   2TUVWXY51SE Z  8 ");
char rev(char a){
	if(isdigit(a))	return reverse[(int)(a-'1'+26)];
	if(isalpha(a))	return reverse[(int)(a-'A')];
}

int main()
{
	string input;
	string output[4] = {
		" -- is not a palindrome.",
		" -- is a regular palindrome.",
		" -- is a mirrored string.",
		" -- is a mirrored palindrome."
	};

	while(cin >> input){
		int mir = 2, pal = 1;
		int len = input.length();
		for(int i = 0; i < len/2+1; i++){
			if(input[i] != input[len - i -1])	pal = 0;
			if(rev(input[i]) != input[len - i -1])	mir = 0;
		}
		
		int flag = mir + pal;
		cout << input << output[flag] << "\n\n";
	}
	return 0;
}
