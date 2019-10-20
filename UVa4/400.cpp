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
string filenames[maxn];

void print(const string &file, const int &num, char c)
{
	cout << file;
	for(unsigned int i = 0; i < num-file.length(); i++){
		cout << c;
	}
}

int main()
{	_
	int n = 0;
	while(cin >> n){
		int M = 0;
		for(int i = 0; i < n; i++){
			cin >> filenames[i];
			M = max(M, (int)filenames[i].length());
		}

		int cols = (maxcol-M) / (M+2) + 1, rows = (n-1) / cols + 1;
		
		print("", 60 , '-');
		cout << '\n';
		sort(filenames, filenames+n);

		for(int r = 0; r < rows; r++){
			for(int c = 0; c < cols; c++){
				int idx = c * rows + r;
				if(idx < n)	print(filenames[idx], (c == cols-1)? M:M+2, ' ');
			}
			cout << "\n";
		}
	}
	return 0;
}
