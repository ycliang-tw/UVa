#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100005
int ans[MAX];

void build()
{
	for(int i = 1; i <= 100000; i++){
		int tmp = i, sum = i;
		do{	sum += (tmp%10); }while(tmp/=10);
		if(sum <= 100000 && ans[sum] == 0)	ans[sum] = i;
	}
}

int main()
{	
	build();
	
	int num;
	while(~scanf("%d", &num)){
		while(num--){
			int input;
			scanf("%d", &input);
			printf("%d\n", ans[input]);
		}
	}
	return 0;
}
