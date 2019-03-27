#include <iostream>
#include <vector>
using namespace std;

int main(){
	long long a, b, tmp;
	while( cin >> tmp >> b ){
		vector<long long>ans;
		a = tmp;
		while( a >= 1 && b && b != 1 ){
			if(a % b != 0){
				break;
			}else{
				ans.push_back(a);
				a = a/b;
			}
		}
		if( a == tmp || a == 0 || a != 1 || b == 1 || b == 0)
			cout << "Boring!\n";
		else{
			ans.push_back(1);
			for(int i = 0; i < ans.size(); i++){
				cout << ans[i];
				if(i != (ans.size() - 1)){
					cout << ' ';
				}
			}
			cout << '\n';
		}
	}
	return 0;
}
