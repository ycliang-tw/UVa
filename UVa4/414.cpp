#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	int row;
	while(cin >> row && row){
		string ign;
		getline(cin, ign);

		vector<int>ans(row);
		int nmin = 26;
		for(int i = 0; i < row; i++){
			string str;
			getline(cin, str);
		
			int cnt = 0;
			for(int j = 0; j < str.length(); j++){
				if(str[j] != 'X')	cnt++;
			}
			ans[i] = cnt;
			
			if(cnt < nmin)	nmin = cnt;
		}

		int tmp = 0;
		for(int i = 0; i < ans.size(); i++){
			tmp += (ans[i] - nmin);
		}
		cout << tmp << '\n';
	}
	return 0;
}
