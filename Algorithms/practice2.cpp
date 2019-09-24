#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<int> compute_prefix1(string pattern)
{
	int len = pattern.length();
	vector<int> prefix(len, 0);

	int p = 0;
	for(int t = 1; t < len; t++){
		if(pattern[p] == pattern[t]){
			p++;
			prefix[t] = p;
			continue;
		}
		while(p > 0 && pattern[p] != pattern[t]){
			p = prefix[p-1];
		}
		if(p>0) p++;
		prefix[t] = p;
	}

	for(auto it:prefix){
		cout << it << " ";
	}
	cout << endl;

	return prefix;
}


vector<int> compute_prefix2(string str)
{
	int len = str.length();
	vector<int> prefix(len, 0);

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

	for(auto it:prefix){
		cout << it << " ";
	}
	cout << endl;

	return prefix;
}

bool kmp(string pat, string txt, vector<int> prefix)
{
	int plen = pat.length();
	int tlen = txt.length();
	int p = 0;
	bool flag = false;
	for(int t = 0; t < tlen; t++){
		while(p > 0 && pat[p] != txt[t]){
			p = prefix[p-1];
		}
		if(pat[p] == txt[t]){
			p++;
		}
		if(p == plen){
			cout << "found at " << t - plen + 1 << endl;
			flag = true;
			p = prefix[p-1];
		}
	}
	return flag;
}


int main()
{
	string pat("aabaabab");
	string txt("aaabaababaa");
	vector<int> prefix1(compute_prefix1(pat));
	vector<int> prefix2(compute_prefix2(pat));
	if(kmp(pat, txt, prefix2))	cout << "yes\n";
	else	cout << "not found\n";
	return 0;
}
