#include <iostream>
#include <vector>
using namespace std;

char out[4] = {' ', '.', 'x', 'W'};

int main(){
	int ncase, dna[10] = {};
	while(cin >> ncase){
		while(ncase--){
			for(int i = 0; i < 10; i++)	cin >> dna[i];
			vector<int> today(42, 0);
			today[20] = 1;

			for(int i = 0; i < 50; i++){
				
				// output
				for(int j = 1; j <= 40; j++){
					cout << out[today[j]];
				}
				cout << '\n';
				
				// calculate
				vector<int> yesterday(today);
				for(int j = 1; j <= 40; j++){
					today[j] = dna[ yesterday[j-1] + yesterday[j] + yesterday[j+1] ];
				}
			}
			if(ncase != 0) cout << '\n';
		}
	}
	return 0;
}
