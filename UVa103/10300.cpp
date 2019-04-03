#include <iostream>
using namespace std;

int main()
{
	int ncase;
	while( cin >> ncase ){
		while(ncase--){
			int lines;
			long long ans = 0;
			cin >> lines;
			while(lines--){
				long long  x1, x2, x3;
				cin >> x1 >> x2 >> x3;
				ans += x1*x3;
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
