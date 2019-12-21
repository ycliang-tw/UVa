#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdio>
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

const int maxn = 1000+10;
int target[maxn];

int main()
{	
	int n;
	while(scanf("%d", &n) == 1 && n)
	{
		while(1)
		{
			scanf("%d", &target[0]);
			if(target[0] == 0)	break;
			for(int i = 1; i < n; i++){
				scanf("%d", &target[i]);
			}

			stack<int> C;
			int A = 1, B = 0;
			int ok = 1;
			while(B < n){
				if(A == target[B]){ A++; B++; }
				else if(!C.empty() && C.top() == target[B]){ C.pop(); B++; }
				else if(A <= n){ C.push(A++); }
				else{ ok = 0; break; }
			}
			printf("%s\n", (ok)? "Yes" : "No");
		}
		printf("\n");
	}
	return 0;
}
