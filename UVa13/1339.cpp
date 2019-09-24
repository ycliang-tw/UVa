#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iterator>
#include <sstream>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <regex>
#include <tuple>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main()
{	_
    
    string input1, input2;
    while(cin >> input1 >> input2)
    {
        vector<int>in1_cnt(30, 0), in2_cnt(30, 0);
        for(auto it1 = input1.begin(); it1 != input1.end(); it1++)
            in1_cnt[(*it1)-'A']++;
        for(string::iterator it2 = input2.begin(); it2 != input2.end(); it2++)
            in2_cnt[(*it2)-'A']++;
        
        sort(in1_cnt.begin(), in1_cnt.end());
        sort(in2_cnt.begin(), in2_cnt.end());

        int i = 0;
        for(; i < 30; i++){
            if(in1_cnt[i] != in2_cnt[i])
                break;
        }
        if(i != 30){
            cout << "NO\n";
        }else{
            cout << "YES\n";
        }
    }
	return 0;
}
