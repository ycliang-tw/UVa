#include <iostream>
using namespace std;

int main(){
	long long int A, L, ncase = 1;
	while(cin >> A >> L && (A > 0)){
		long long Aout = A, limit = L;
		long long int cnt = 1;
		while(A != 1 && A <= L){
			if(A & 1)	A = 3*A+1;
			else		A = A/2;
			if(A <= L)	cnt++;
		}
		cout << "Case " << ncase
			 << ": A = " << Aout 
			 << ", limit = " << limit
			 << ", number of terms = " << cnt 
			 << '\n';
		ncase++;
	}
	return 0;
}
