#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{	
	int test_case;
	scanf("%d", &test_case);
	while(test_case--){
		char str[100] = {};
		scanf("%s", str);
		int len = strlen(str);
		int p = 1;
		for(; p <= len; p++){
			if(len % p == 0){
				int j = 0;
				for(j = p; j < len; j++){
					if(str[j] != str[j%p])
						break;
				}
				if(j == len){
					printf("%d\n", p);
					break;
				}
			}
		}
		if(test_case)
			puts("");
	}
	return 0;
}
