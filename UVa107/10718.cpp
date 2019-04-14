#include <iostream>
using namespace std;

int main(){
	unsigned int N, L, U;
	while(cin >> N >> L >> U){
		unsigned int M = 0;
		for(int i = 31; i >= 0; i--){
			unsigned int tmp = 0;
			unsigned int num = (1U << i);
//			cout << "i == " << i << ", num == " << num << '\n';
			if(N & num){
				tmp = M + num;
				if(tmp <= L){
					M = M + num;
				}
			}else{
				tmp = M + num;
				if(tmp <= U){
					M = M + num;
				}
			}
		}
		cout << M << '\n';
	}
	return 0;
}
