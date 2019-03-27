#include <iostream>
#include <string>
using namespace std;

int test(int a, int *flag){
	if(a == 9)
		return 1;
	else if(a % 9 == 0){
		int tmp = 0;
		while(a){
			tmp += a%10;
			a /= 10;
		}
		return 1+test(tmp, flag);
	}else{
		(*flag) = 0;
		return 0;
	}
}

int main(){
	string input;
	while(cin >> input){
		if(input[0] == '0')
			break;
		int flag = 1, degree = 0, sum = 0;
		for(int i = 0; i < input.length(); i++){
			if(input[i] >= '0' && input[i] <= '9'){
				sum = sum + (input[i] - '0');
			}
		}
		degree = test(sum, &flag);
		if(flag){
			cout << input << " is a multiple of 9 and has 9-degree " << degree << ".\n";
		}
		else{
			cout << input << " is not a multiple of 9.\n";
		}
	}
	return 0;
}
