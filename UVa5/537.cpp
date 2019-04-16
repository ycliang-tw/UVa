#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
	int nline;
	string arr[3] 	= { "I=", "U=", "P=" };
	string unit[3] 	= { "A", "V", "W"};
	while(cin >> nline){
		string input;
		getline(cin, input);
		for(int i = 1; i <= nline; i++){
			cout << "Problem #" << i << '\n';

			getline(cin, input);
			
			bool f[3] = { 0, 0, 0 };
			double I = -1.0, U = -1.0, P = -1.0;
			for(int j = 0; j < 3; j++){

				int lpos = input.find(arr[j]);
				double tmp = 0.0;
				if(lpos != string::npos){
					f[j] = true;
					string subin(input.begin()+lpos, input.end());
					int rpos = subin.find(unit[j]);
					double base = 10.0, decimal = 1.0, sign = 1.0;
					int flag = 0;
					
					for(int k = 2; k < rpos; k++){
						if(flag)	decimal *= 0.1;
						if(subin[k] == '-'){
							sign = -1;
						}else if(subin[k] == '.'){
							base = 1.0, flag = 1;
						}else if(subin[k] == 'm'){
							tmp = tmp * 0.001;
						}else if(subin[k] == 'k'){
							tmp = tmp * 1000.0;
						}else if(subin[k] == 'M'){
							tmp = tmp * 1000000.0;
						}else{
							tmp = tmp * base + (double)(subin[k]-'0') * decimal;
//							cout << "tmp " << tmp << ", input[k] " << subin[k] << '\n';
						}
					}
					
					switch(j){
						case 0:	I = sign*tmp; break;
						case 1: U = sign*tmp; break;
						case 2: P = sign*tmp; break;
					}
				}
			}

			if(f[0] == 0)		cout << "I=" << setprecision(2) << fixed << P/U << "A\n\n";
			else if(f[1] == 0)	cout << "U=" << setprecision(2) << fixed << P/I << "V\n\n";
			else 				cout << "P=" << setprecision(2) << fixed << I*U << "W\n\n";

		}
	}
	return 0;
}
