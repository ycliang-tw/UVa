#include <iostream>
#include <string>
using namespace std;


int process(string ans, string guess){
	int win = 0, chicken = 1, lose = 2;
	int chance = 7, i, j;
	string com(ans.length(), ' ');
//	cout << "len == " << com.length() << '\n';

	for(i = 0; i < guess.length(); i++){
		bool hit = false;
		for(j = 0; j < ans.length(); j++){
			if(guess[i] == ans[j] && guess[i] != ' '){
				ans[j] = ' ';
				hit = true;
			}
		}
		for(j = i+1; j < guess.length(); j++){
			if(guess[i] == guess[j]){
				guess[j] = ' ';
			}
		}
		if(!hit && guess[i] != ' ')	chance--;
		if((ans == com)) break;
//		cout << "chance == " << chance << '\n';
//		cout << "ans == " << ans << '\n';
	}
	
	if(chance > 0 && (ans == com))	return win;
	if(chance > 0)					return chicken;
	return lose;
	
}

int main(){
	int caseID;
	while(cin >> caseID && (~caseID)){
		cout << "Round " << caseID << '\n';
		
		string ans, guess;
		string out[3] = { "You win.", "You chickened out.", "You lose." };
		cin >> ans >> guess;
		
		int flag = process(ans, guess);
		cout << out[flag] << '\n';
	}
	return 0;
}
