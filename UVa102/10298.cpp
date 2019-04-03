#include <iostream>
#include <string>
#include <vector>
using namespace std;

int kmp_prefix(string pat)
{
	int len  = pat.length();
	int q    = 0;
	vector<int>prefix(len);

	prefix[0] = 0;

	for(int i = 1; i < len; i++){
		while(q > 0 && pat[q] != pat[i]){
			q = prefix[q-1];
		}
		if(pat[q] == pat[i]){
			q++;
		}
		prefix[i] = q;
	}
	return prefix[len-1];
}


int main()
{
	string input;
	while( getline(cin, input) ){
		if(input == ".")	break;	
		int n   = input.length();
		int pre = kmp_prefix(input);
		cout << n/(n-pre) << '\n';
	}
	return 0;
}
