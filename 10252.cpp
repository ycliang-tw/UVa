#include <stdio.h>
int main(){
	char str[1003] = {};
	while(fgets(str, sizeof(str), stdin)){
		int a[128] = {}, b[128] = {};
		for(int i = 0; str[i] != '\n' && str[i] != '\0'; i++){
			a[ str[i] ]++;
		}
		fgets(str, sizeof(str), stdin);
		for(int i = 0; str[i] != '\n' && str[i] != '\0'; i++){
			b[ str[i] ]++;
		}
		for(int i = 0; i < 128; i++){
			for(int j = 0; j < a[i] && j < b[i]; j++){
				printf("%c", i);
			}
		}
		puts("");
	}
	return 0;
}
