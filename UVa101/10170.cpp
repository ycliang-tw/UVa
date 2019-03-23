#include <stdio.h>

int main(){
	unsigned long long start, ith;
	while( ~scanf("%lld %lld", &start, &ith) ){
		unsigned long long tmp = 0, i;
		for(i = start; tmp < ith; i++){
			tmp += i;
		}
		printf("%lld\n", i-1);
	}
	return 0;
}
