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

void parse_addr(const string &s, string &user, string &mta)
{
	int pos = s.find('@');
	user = s.substr(0, pos);
	mta = s.substr(pos+1);
}

int main()
{	_
	
	string s, t, user1, mta1, user2, mta2;
	int num;
	set<string>	addr;

	// parse all mtas and their users, turn them into email address
	while(cin >> s && s != "*"){
		cin >> s >> num;
		while(num--){
			cin >> t;
			addr.insert(t + "@" + s);
		}
	}

	// parse sender and receivers
	while(cin >> s && s != "*"){
		parse_addr(s, user1, mta1);	// sender's info

		vector<string> mtas;
		map<string, vector<string> > dest;
		set<string> visited;
		while(cin >> t && t != "*"){	// the receivers' info
			parse_addr(t, user2, mta2);

			if(visited.count(t))
				continue;

			visited.insert(t);

			if(!dest.count(mta2)){
				mtas.push_back(mta2);
				dest[mta2] = vector<string>();
			}
			dest[mta2].push_back(t);
		}

		getline(cin, t);		// gets "\n" from "*"
		
		// parse mail data
		string data;
		while(getline(cin, t) && t[0] != '*'){
			data += "     " + t + "\n";
		}

		for(unsigned int i = 0; i < mtas.size(); i++){
			mta2 = mtas[i];
			vector<string> users = dest[mta2];
			cout << "Connection between " << mta1 << " and " << mta2 << endl;
			cout << "     HELO " << mta1 << endl;
			cout << "     250\n";
			cout << "     MAIL FROM:<" << s  << ">\n";
			cout << "     250\n";
			
			bool ok = false;
			for(unsigned int i = 0; i < users.size(); i++){
				cout << "     RCPT TO:<" << users[i] << ">\n";
				if(addr.count(users[i])){
					ok = true;
					cout << "     250\n";
				}else{
					cout << "     550\n";
				}
			}

			// data
			if(ok){
				cout << "     DATA\n";
				cout << "     354\n";
				cout << data;
				cout << "     .\n";
				cout << "     250\n";
			}
			cout << "     QUIT\n";
			cout << "     221\n";
		}
	}

	return 0;
}
