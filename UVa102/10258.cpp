#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

struct man{
	int id, time, solved;
	int prob[10];
	bool sol[10];
	bool sub;
};

bool cmp(struct man a, struct man b){
	if(a.solved == b.solved && a.time == b.time){
		return a.id < b.id;
	}else if(a.solved == b.solved){
		return a.time < b.time;
	}
	return a.solved > b.solved;
}

int main(){
	int ncase;
	while(cin >> ncase){
		string str;
		getline(cin, str);
		getline(cin, str);
		for(int i = 0; i < ncase; i++){
			vector<struct man>arr(101);

			while(getline(cin, str)){
				if(str == "") break;
				stringstream ss;
				int id, prob, time;
				char c;
				ss << str;
				ss >> id >> prob >> time >> c;

				arr[id].id = id;
				arr[id].sub = true;
				if(c == 'I'){
					arr[id].prob[prob] += 20;
				}else if(c == 'C'){
					if(arr[id].sol[prob] != true){
						arr[id].solved++;
						arr[id].sol[prob] = true;
						arr[id].time = arr[id].time + time + arr[id].prob[prob];
					}
				}
			}
			sort(arr.begin(), arr.end(), cmp);
			if(i != 0) cout << '\n';
			for(int j = 0; j < 101; j++){
				if(arr[j].sub){
					cout << arr[j].id << " " << arr[j].solved << " " << arr[j].time << '\n';
				}
			}
		}
	}
	return 0;
}
