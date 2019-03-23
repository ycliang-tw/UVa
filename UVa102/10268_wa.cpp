#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// cannot use long long in "(cmath)pow"
// because pow only support floating point 
// if number is too big, return value will overflow

//long long coef[1000000];


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
		vector<long long>coef;
		while(getline(ss, input, ' ')){				// the delimiter will be used exactly the number we specified, so in this case, 
			stringstream sa;						// if there is multiple white space between input numbers, the result will not be as expected.
			cout << "tmp string " << input << '\n';
			sa << input;
			long long tmp;
			sa >> tmp;
			cout << "long long " << tmp << "\n";
			coef.push_back(tmp);
		}
		long long ans = 0;
		auto it = coef.rbegin(); it++;
		for(long long i = 1; it != coef.rend(); i++, it++){
			ans += (*it) * i * mpow(x, i-1);
		}
		cout << ans << '\n';

	}
	return 0;
}
