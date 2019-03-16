#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int maxlen = 1000000;								// use each bit as an indication, int is 32-bit,
int not_prime[(maxlen>>5) +1];							// each element can be  used to indicate up to 32 numbers whether a number is prime or not
#define SET(x) ( not_prime[x>>5]|=(1<<(x&31)) )			// if a bit is set to 1 means the number the bit represents is not prime,
#define GET(x) ( not_prime[x>>5]>>(x&31)&1 )			// vice versa.




int prime[700000], pt = 0;

void sieve(){
	register int i, j, k;								// store i, j, k in cpu register for faster access
	SET(1);
	int sqrt_maxlen = (int)sqrt(maxlen);
	for(i = 2; i <= maxlen; i++){                       // has to be maxlen to avoid incorrect judgement 
		if( !GET(i) ){									// because we have here a prime array, if we do not calculate to the maxlen,		
			prime[pt++] = i;							// we will not put some of the prime number into the prime array
			for(j = maxlen/i, k = i*j; k > i ; j--, k -= i){	// for(j = maxlen/i, k = i*j; j >= i; j--, k -= i) is better for it does SET fewer times
				SET(k);
			}
		}
	}
}
/*
void outprime(){
	for(int i = 0; i < pt; i++){
		cout << "prime[" << i << "] = " << prime[i] << endl;
	}
}
*/
int isprime(int n){
	if( n < maxlen ){
		return !GET(n);
	}
	int sqrt_n = (int)sqrt(n);
	for(int i = 0; i < pt && prime[i] <= sqrt_n; i++){
		if(n%prime[i] == 0)
			return 0;
	}
	return 1;
}



int main(){
	sieve();
	int L, U;
	while(cin >> L >> U){
		int _min = 2147483647, _max = -_min;
		int last = -1, flag = 0;
		int p1 = 0, p2 = 0, p3 = 0, p4 = 0;
		int tmp;
		for(long long int a = L; a <= U; a++){			// This a has to be long long in order to avoid overflow
			if(isprime(a)){								// for example a = 2147483647 and then a++ will be -2147483648
				if(last == -1){							// so a will still be < U and continue to execute the for loop
					last = a;							// and then access the negative index of not_prime array
				}else{
					flag = 1;
					tmp = a - last;
					if(tmp > _max){
						_max = tmp;
						p1 = last, p2 = a;
					}
					if(tmp < _min){
						_min = tmp;
						p3 = last, p4 = a;
					}
					last = a;
				}
			}
		}
		if(flag == 0)
			puts("There are no adjacent primes.");
		else
			printf("%d,%d are closest, %d,%d are most distant.\n", p3, p4, p1, p2);
	}
	return 0;
}







