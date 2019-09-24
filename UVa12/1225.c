#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{	
	int num;
	scanf("%d", &num);
	while(num--){
		int arr[10] = {};
		int input;
		scanf("%d", &input);
		for(int i = 1; i <= input; i++){
			int tmp = i;
			while(tmp){
				arr[tmp%10]++;
				tmp/=10;
			}
		}
		for(int i = 0; i < 10; i++){
			if(i == 0) printf("%d", arr[i]);
			else	   printf(" %d", arr[i]);
		}
		puts("");
	}
	return 0;
}
