#include <stdio.h>
#include <string.h>

int main(){
	char s[105][105] = {}, a[105][105] = {};
	int i = 0, longest = 0;
	while(fgets(s[i], 103, stdin)){
		if(strlen(s[i]) > longest){
			longest = strlen(s[i]);
		}
		i++;
	}
	
	memset(a, ' ', sizeof(a));
	for(int idx = 0; idx < i; idx++){
		for(int jdx = 0; s[idx][jdx] != '\n' && s[idx][jdx] != '\0'; jdx++){
			a[jdx][i-1-idx] = s[idx][jdx];
		}
	}
	for(int j = 0; j < longest -1; j++){
		a[j][i] = '\0';
		puts(a[j]);
	}


	return 0;
}
