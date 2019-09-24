#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


vector<int> prefix_function(string str)
{
	int len = str.length();
	vector<int>prefix(len, 0);
	int p = 0;
	for(int t = 1; t < len; t++){
		while(p > 0 && str[p] != str[t]){
			p = prefix[p-1];
		}
		if(str[p] == str[t]){
			p++;
		}
		prefix[t] = p;
	}
	
	for(auto it : prefix){
		cout << it << " ";
	}
	cout << endl;

	return prefix;

}

void KMP(string text, string pat, vector<int>prefix)
{
	int tlen = text.length();
	int plen = pat.length();
	int p = 0, t = 0;
	for(int t = 0; t < tlen; t++){
		while(p > 0 && text[t] != pat[p]){
			p = prefix[p-1];
		}
		if(text[t] == pat[p]){
			p++;
		}
		if(p == plen){
			cout << "found pattern at " << t - plen + 1 << endl;
			p = prefix[p-1];
		}
	}

}


int main()
{
	string pattern1("abcdabca");
	string pattern2("aabaabaaa");
	string text1("abcaabcaabcdabcaa");
	string text2("aabacaacaabaabaaaab");

	vector<int> pre1( prefix_function(pattern1) );
	vector<int> pre2( prefix_function(pattern2) );

	cout << "text1 find pattern at 8\n";
	KMP(text1, pattern1, pre1);
	cout << "text2 find pattern at 8\n";
	KMP(text2, pattern2, pre2);
	return 0;
}
