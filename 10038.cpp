#include <stdio.h>

int main(){
	int num;
	while(~scanf("%d", &num)){
		int input[3001] = {}, tag[3001] = {}, i;
		for(i = 0; i < num; i++){
			scanf("%d", &input[i]);
		}
		for(i = 1; i < num; i++){
			int tmp = input[i] - input[i-1];
			if(tmp < 0){
				tmp = -tmp;
			}
			if(tmp < num){
				tag[tmp] = 1;
			}
		}
		for(i = 1; i < num; i++){
			if(tag[i] != 1)
				break;
		}
		if(i != num)
			puts("Not jolly");
		else
			puts("Jolly");
	}
	return 0;
}
