#include <iostream>
#include <map>
#include <queue>
using namespace std;


int main()
{
	int nq, ncase = 0;
	const int qmax = 1010;
	while(cin >> nq && nq){
		cout << "Scenario #" << ++ncase << '\n';
		
		map<int, int> team;
		for(int i = 1; i <= nq; i++){
			int qlen;
			cin >> qlen;
			for(int j = 0; j < qlen; j++){
				int id;
				cin >> id;
				team[id] = i;
			}
		}
		

		queue<int>Q, qs[qmax];
		while(1){
			string op;
			cin >> op;
			if(op == "STOP"){
				break;
			}else if(op == "ENQUEUE"){
				int id;
				cin >> id;
				int tid = team[id];
				if(qs[tid].empty())	Q.push(tid);
				qs[tid].push(id);
			}else if(op == "DEQUEUE"){
				int tid = Q.front();
				cout << qs[tid].front() << '\n';
				qs[tid].pop();
				if(qs[tid].empty())	Q.pop();
			}
		}
		cout << '\n';
	}
	return 0;
}
