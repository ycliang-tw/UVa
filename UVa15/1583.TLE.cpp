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

int cal_digit(int num)
{
	int i = 0;
	for(; i < 6; i++){
		int div = pow(10, i);
		if(num/div <= 9 && num/div >= 1)
			break;
	}
	return i+1;
}

int main()
{
	int num;
	while(cin >> num){
		while(num--){

			int in;
			cin >> in;

			int digit = cal_digit(in);

			int start = (digit == 1)? 1 : pow(10, digit-2);
			
			for(; start < in; start++){
				int tmp = start, ans = start;
				while(tmp){
					ans += (tmp%10);
					tmp /= 10;
				}
				if(ans == in)
					break;
			}
			cout << ( (start == in)? 0 : start ) << '\n';
		}
	}
	return 0;
}
