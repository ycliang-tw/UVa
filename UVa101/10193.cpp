#include <iostream>
#include <string>
#include <cmath>
using namespace std;

long long int GCD(long long a, long long b){
	if(a % b == 0)
		return b;
	else
		return GCD(b, a%b);
}

int main(){
	int ncase;
	while( cin >> ncase ){
		for(int i = 1; i <= ncase; i++){
			string str1, str2;
			cin >> str1 >> str2;
			long long in1 = 0, in2 = 0;
			for(int it = 0; it < str1.length(); it++){
				if(str1[it] == '1'){
					in1 += pow(2, (str1.length() - it -1));
				}
			}
			for(int it = 0; it < str2.length(); it++){
				if(str2[it] == '1'){
					in2 += pow(2, (str2.length() - it -1));
				}
			}
//			cout << in1 << " " << in2 << '\n'; 
			long long int gcd = GCD(in1, in2);
			if(gcd != 1)
				cout << "Pair #" << i << ": All you need is love!\n";
			else 
				cout << "Pair #" << i << ": Love is not all you need!\n";
		}

	}
	return 0;
}
