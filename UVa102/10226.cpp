#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

int main(){
	int ncase;
	while(cin >> ncase){
		string ign, tname;
		getline(cin, ign);
		for(int i = 0; i < ncase; i++){
			if(i == 0) getline(cin, ign);
			int cnt = 0;
			map<string, int>cal;
			while( getline(cin, tname) ){
				if(tname.empty())	break;
				cnt++;
				auto it = cal.find(tname);
				if( it != cal.end() ){
					it->second++;
				}else{
					cal[tname] = 1;
				}
			}
			if( i != 0 ) cout << '\n';
			for(auto it : cal){
				cout << it.first << " " << fixed << setprecision(4) << (double)((double)100*it.second/(double)cnt) << "\n";
			}
		}

	}
	return 0;
}
