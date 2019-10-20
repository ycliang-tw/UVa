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
const int maxn = 30;
unsigned int n;
vector<int> pile[maxn];

void find_block(int id, unsigned int &p, unsigned int &h)
{
	for(p = 0; p < n; p++){
		for(h = 0; h < pile[p].size(); h++){
			if(id == pile[p][h])
				return;
		}
	}
}

void clear_above(int p, int h)
{
	for(unsigned int i = h+1; i < pile[p].size(); i++){
		int tmp = pile[p][i];
		pile[tmp].push_back(tmp);
	}
	pile[p].resize(h+1);
}

void pile_onto(int p, int h, int p2)
{
	for(unsigned int i = h; i < pile[p].size(); i++){
		pile[p2].push_back(pile[p][i]);
	}
	pile[p].resize(h);
}

void print()
{
	for(unsigned int i = 0; i < n; i++){
		printf("%d:", i);
		for(unsigned int j = 0; j < pile[i].size(); j++){
			printf(" %d", pile[i][j]);
		}
		printf("\n");
	}
}

int main()
{	_
	int a, b;
	cin >> n;
	string s1, s2;
	for(unsigned int i = 0; i < n; i++){
		pile[i].push_back(i);
	}

	while(cin >> s1 >> a >> s2 >> b){
		unsigned int pa, pb, ha, hb;
		find_block(a, pa, ha);
		find_block(b, pb, hb);

		if(a == b || pa == pb)
			continue;
		
		if(s2 == "onto")	clear_above(pb, hb);
		if(s1 == "move")	clear_above(pa, ha);
		pile_onto(pa, ha, pb);
	}

	print();
	return 0;
}
