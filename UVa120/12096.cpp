#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <iterator>
#include <algorithm>
using namespace std;

typedef set<int> Set;					// store the setID of its elements
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

map<Set, int> IDcache;					// store the mapping from set to setID, and setID means the cardinality of the set
vector<Set> Setcache;					// store all the present sets


int ID(Set x)							// do the conversion from set to setID
{
	if(IDcache.count(x))	return IDcache[x];
	Setcache.push_back(x);
	return IDcache[x] = Setcache.size() -1;
}


int main()
{
	int ncase;
	while(cin >> ncase){
		while(ncase--){
			int nop;
			cin >> nop;

			stack<int> s;

			for(int i = 0; i < nop; i++){
				string op;
				cin >> op;
				
				Set x0;
				if(op == "PUSH")	s.push( ID(x0) );
				else if(op == "DUP")	s.push(s.top());
				else{
					Set x1 = Setcache[s.top()]; s.pop();
					Set x2 = Setcache[s.top()]; s.pop();
					Set x;
					if(op == "UNION")	set_union(ALL(x1), ALL(x2), INS(x));
					else if(op == "INTERSECT")	set_intersection(ALL(x1), ALL(x2), INS(x));
					else if(op == "ADD"){x = x2; x.insert(ID(x1));}
					s.push(ID(x));
				}
				cout << Setcache[s.top()].size() << '\n' ;
			}
			cout << "***\n";
		}
	}
	return 0;
}
