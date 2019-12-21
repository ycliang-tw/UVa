#include <algorithm>
#include <cmath>
//#include <iostream>
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
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxn = 1000;

int n, t[5], quan;			// number of program, time, quantum
char prog_exec[maxn][10];	// commands to be executed
int com[maxn];				// line = com[pid], com stores the current line of the pid'th program
int locked;
int var[26];				// variable

deque<int> readyQ;			// when parsed, push back. when blocked, push front
queue<int> blockQ;			// when blocked, push back 

void run(int pid)
{
	int q = quan;
	while(q > 0){
		char *p = prog_exec[com[pid]];
		switch(p[2]){
			case '=':	// assign
				var[p[0] - 'a'] = isdigit(p[5]) ? (p[4]-'0') * 10 + (p[5] -'0') : (p[4] - '0');
				q -= t[0];
				break;
			case 'i':	// print
				printf("%d: %d\n", pid+1, var[p[6] - 'a']);
				q -= t[1];
				break;
			case 'c':	// lock
				if(locked){
					blockQ.push(pid);
					return;
				}
					locked = true;
					q -= t[2];
				break;
			case 'l':	// unlock
				locked = false;
				if(!blockQ.empty()){
					int pid2 = blockQ.front();	blockQ.pop();
					readyQ.push_front(pid2);
				}
				q -= t[3];
				break;
			case 'd':	// end
				return;
				break;
		}
		com[pid]++;
	}
	readyQ.push_back(pid);
}


int main()
{	
	int kase;
	scanf("%d", &kase);

	while(kase--){
		scanf("%d %d %d %d %d %d %d\n", &n, &t[0], &t[1], &t[2], &t[3], &t[4], &quan);
		memset(var, 0, sizeof(var));
		
		int line = 0;
		for(int i = 0; i < n; i++){
			fgets(prog_exec[line++], 10, stdin);
			com[i] = line-1;
			while(prog_exec[line-1][2] != 'd'){
				fgets(prog_exec[line++], 10, stdin);
			}
			readyQ.push_back(i);
		}
/*	
		for(int i = 0; i < line; i++){
			printf("%d: %s", i, prog_exec[i]);
		}
*/
		locked = false;
		while(!readyQ.empty()){
			int pid = readyQ.front();
			readyQ.pop_front();
			run(pid);
		}
		
		if(kase) puts("");
	}

	return 0;
}
