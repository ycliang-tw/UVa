#include <iostream>
#include <string>
using namespace std;

int main(){
	string input;
	while( getline(cin, input) ){
		long long sum = 0;
		int ans = 0, bmin = 2, tmp = 0;
		for(int i = 0; i < input.length(); i++){
			if(input[i] >= '0' && input[i] <= '9'){
				tmp = input[i] - '0';
				sum += tmp;
			}else if(input[i] >= 'A' && input[i] <= 'Z'){
				tmp = input[i] - 'A' + 10;
				sum += tmp;
			}else if(input[i] >= 'a' && input[i] <= 'z'){
				tmp = input[i] - 'a' + 36;
				sum += tmp;
			}
			if(tmp >= bmin)
				bmin = tmp + 1;
		}

//		cout << "sum == " << sum << '\n';
//		cout << "bmin == " << bmin << '\n';
		for(int i = bmin; i <= 62; i++){
			if(sum % (i-1) == 0){
				ans = i;
				break;
			}
		}
		if(ans)
			cout << ans << '\n';
		else
			cout << "such number is impossible!\n";
	}
	return 0;
}
