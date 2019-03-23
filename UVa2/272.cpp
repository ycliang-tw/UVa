#include <stdio.h>

int main(){
	char c;
	int flag = 1;
	while((c=getchar())!= EOF){
		if(c == '"'){
			if(flag){
				printf("``");
				flag = 0;
			}else{
				printf("''");
				flag = 1;
			}
		}else{
			putchar(c);
		}
	}
	return 0;
}
