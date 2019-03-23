#include <stdio.h>

int main(){
	int lines;
	while(~scanf("%d", &lines)){
		while(lines--){
			int num, deccnt = 0, hexcnt = 0;
			scanf("%d", &num);
			long long dec = 0, hex = num;
			while(num){
				dec = dec*10 + num%10;
				num /= 10;
			}
			num = hex;
			hex = 0;
			while(dec){
				hex = hex*16 + dec%10;
				dec /= 10;
			}
			dec = num;
//			printf("dec == %d, hex == %d\n", dec, hex);
			while(dec || hex){
				if((dec & 1) == 1){
//					printf("dec == %lld\n", dec);
					deccnt++;
				}
				if((hex & 1) == 1){
					hexcnt++;
				}
				dec = dec >> 1;
				hex = hex >> 1;
			}
			printf("%lld %lld\n", deccnt, hexcnt);
		}
	}
}
