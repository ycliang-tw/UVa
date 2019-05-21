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

map<int, int> table;
map<int, int>::iterator iter;

void setup()
{
	for(int i = 1; i <= 100000; i++){
		int tmp = i, sum = i;
		while(tmp){
			sum += (tmp % 10);
			tmp /= 10;
		}
		
		iter = table.find(sum);
		if(iter == table.end()){
			table[sum] = i;
		}
	}
}

int main()
{	_
	int num;
	setup();
	while(cin >> num){
		while(num--){
			int input;
			cin >> input;

			iter = table.find(input);
			if( iter != table.end() ){
				cout << iter->second << '\n';
			}else
				cout << "0\n";
		}
	}
	return 0;
}
