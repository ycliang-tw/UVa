#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{	
	int num;
	scanf("%d", &num);	// while(~scanf()) gets TLE !
	while(num--){
		char arr[100] = {};
		int score = 0;
		
		scanf("%s", arr);
		
		for(int i = 0; i < arr[i]; i++){
			int tmp = 0;
			while(arr[i++] == 'O'){
				tmp++;
			}
			i--;
			score += (1+tmp)*tmp/2;
//				printf("i= %d, tmp %d, score %d\n", i, tmp, score);
		}
		
		printf("%d\n", score);
	}
	
	return 0;
}
