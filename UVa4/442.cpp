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

struct Matrix{
	int row, col;
public:
	Matrix(int row = 0, int col = 0):row(row),col(col){}
} m[26];


int main()
{	_
	int num;
	cin >> num;
	char name;
	for(int i = 0; i < num; i++){
		cin >> name;
		int id = name - 'A';
		cin >> m[id].row >> m[id].col;
	}

	string expr;
	while(cin >> expr){

		int len = expr.length();
		int mul = 0;
		bool ok = true;
		stack<Matrix> s;
		
		for(int i = 0; i < len; i++){
			if(isalpha(expr[i])){
				s.push(m[ expr[i] - 'A' ]);
			}else if(expr[i] == ')'){
				Matrix m2 = s.top(); s.pop();
				Matrix m1 = s.top(); s.pop();
				if(m1.col != m2.row){ok = false; break;}
				mul += m1.row * m1.col * m2.col;
				s.push(Matrix(m1.row, m2.col));
			}
		}
		if(ok)	cout << mul << endl;
		else	cout << "error\n";
	}
	
	return 0;
}
