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

const int maxcol = 60;
const int maxn = 100+5;
string filemames[maxn];

int main()
{	_
	int n = 0;
	while(cin >> n){
		int M = 0;
		for(int i = 0; i < n; i++){
			cin >> filenames[i];
			M = max(M, filenames[i].length());
		}

		int cols = (maxcol-M) / (M+2) + 1, rows = (n-1) / cols + 1;
		
		print("", 60 , '-');
		
		for(int r = 0; r < rows; r++){
			for(int c = 0; c < cols; c++){
				int idx = r * cols + c;
				if(idx < n)	print(filenames[idx], (c == cols-1)? M:M+2, ' ');
			}
			cout << "\n";
		}
	}
	return 0;
}
