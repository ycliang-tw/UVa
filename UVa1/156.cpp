#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std; 

string repr(const string& s){
	string ans = s;
	for(int i = 0; i < ans.length(); i++){
		ans[i] = tolower(ans[i]);
	}
	sort(ans.begin(), ans.end());
	return ans;
}


int main()
{
	string s;
	vector<string>words;
	map<string, int>cnt;
	while(cin >> s){
		if(s[0] == '#')	break;
		
		words.push_back(s);
		string r = repr(s);
		if(!cnt.count(r))	cnt[r] = 0;
		cnt[r]++;
	}

	vector<string>ans;
	for(vector<string>::iterator it = words.begin(); it != words.end(); it++){
		if(cnt[repr(*it)] == 1)	ans.push_back(*it);
	}
	sort(ans.begin(), ans.end());
	for(auto i : ans){
		cout << i << '\n';
	}
	return 0;
}
