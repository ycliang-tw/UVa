#include <iostream>
using namespace std;

#define MAX 1000000

int comptable[(MAX>>5)+1];

#define SET(x) ( comptable[x>>5] |= 1<<(x&31) )
#define GET(x) ( comptable[x>>5]>>(x&31) & 1 )

void sieve(){
	SET(0);
	SET(1);
	register int i, j, k;
	for(i = 2; i <= MAX; i++){
		if(GET(i) == 0){
			for(j = MAX/i, k = j*i; j >= i; j--, k -= i){
				if(GET(i) == 0)
					SET(k);
			}
		}
	}
}

int main(){
	sieve();
	int input;
	while( cin >> input ){
		if(GET(input) == 0){
			int tmp1 = 0, tmp2 = input;
			while(tmp2){
				tmp1 = tmp1 *10 + tmp2%10;
				tmp2 /= 10;
			}
			if(GET(tmp1) == 0 && (tmp1 != input)){
				cout << input << " is emirp.\n";
			}else{
				cout << input << " is prime.\n";
			}
		}else{
			cout << input << " is not prime.\n";
		}
	}
	return 0;
}
