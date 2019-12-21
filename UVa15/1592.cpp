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
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

typedef pair<int, int> PII;

const int max_row = 10000 + 5;
const int max_col = 10 + 5;

int row, col, db[max_row][max_col], cnt;
map<string, int>id;

int ID(const string & str)
{
	if(id.count(str) == 0){
		id[str] = ++cnt;	
	}
	return id[str];
}

void find()
{
	for(int c1 = 0; c1 < col; c1++){
		for(int c2 = c1+1; c2 < col; c2++){
			map<PII,int>tmp;
			for(int r = 0; r < row; r++){
				PII p = make_pair(db[r][c1], db[r][c2]);
				if(tmp.count(p)){
					printf("NO\n");
					printf("%d %d\n", tmp[p]+1, r+1);
					printf("%d %d\n", c1+1, c2+1);
					return;
				}
				tmp[p] = r;
			}
		}
	}
	printf("YES\n");
}

int main()
{
	string input;
	while(getline(cin, input)){
		stringstream ss(input);
		if(!(ss >> row >> col))	break;
		cnt = 0;
		id.clear();
		for(int i = 0; i < row; i++){
			getline(cin, input);
			int lastpos = -1;
			for(int j = 0; j < col; j++){
				unsigned int pos = input.find(",", lastpos+1);
				if(pos == string::npos)	pos = input.length();
				db[i][j] = ID(input.substr(lastpos+1, pos - lastpos - 1)); // no comma should be included pos "-1" -lastpos
				lastpos = pos;
			}
		}
		find();
	}
	return 0;
}
