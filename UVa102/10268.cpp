#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// cannot use long long in "(cmath)pow"
// because pow only support floating point 
// if number is too big, return value will overflow

long long coef[1000000];


long long mpow(long long a, long long b){
	if(a == 1 || b == 0)
		return 1;
	if( (b & 1) == 0){					// b&1 must be braced, otherwise "1 == 0" will be judged first and it's always false 
		return mpow(a*a, b/2);
	}else{
		return a * mpow(a*a, b/2);
	}
}


int main(){
	long long x;
	while( cin >> x ){
		string input;
		stringstream ss;
		getline(cin, input);		// for clearing out '\n' that cin left 
		getline(cin, input);
		ss << input;
		long long n = 0;
		while(ss >> coef[n]){
			n++;
		}
		long long ans = 0;
		for(long long i = 0; i < n-1; i++){
			ans += mpow(x, i) * (i+1) * coef[n-i-2];
		}
		cout << ans << '\n';

	}
	return 0;
}
