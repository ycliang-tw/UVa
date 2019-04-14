#include <iostream>
#define Bit(i) (1U<<i)
#define And(x,i) ((x) & (Bit(i)))
#define Or(x,i) ((x) | (Bit(i)))
using namespace std;

int main(){
	unsigned int N, L, U;
	while(cin >> N >> L >> U){
		unsigned int M = 0;
		for(int i = 31; i >= 0; i--){
			if(Or(M, i) <= (And(N, i)? L : U))	M = Or(M, i);
		}
		cout << M << '\n';
	}
	return 0;
}
