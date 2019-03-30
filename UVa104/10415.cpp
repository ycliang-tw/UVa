#include <stdio.h>
#include <string.h>

int table[14][11] = {	// table for finger
	{0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1},
	{0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0},
	{0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0},
	{0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0},
	{0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0},
	{0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0},
	{0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
};


int main(){
	int ncase;
	while( scanf("%d", &ncase) == 1 ){
		char str[205] = {};					// be careful!  will be WA if char str[201]
		getchar();
		for(int i = 0; i < ncase; i++){
			fgets(str, sizeof(str), stdin);
			int cnt[11] = {}, f[11] = {};
			for(int j = 0; str[j] && str[j] != '\0'; j++){
				int tmp[11] = {};
				if(str[j] >= 'a' && str[j] <= 'g'){
					memcpy(tmp, table[str[j] - 'a'], sizeof(tmp));
				}else if(str[j] >= 'A' && str[j] <= 'G'){
					memcpy(tmp, table[str[j] - 'A' + 7], sizeof(tmp));
				}else{
					continue;
				}
					
				for(int k = 1; k <= 10; k++){
					if(f[k] == 0 && tmp[k] == 1){
						cnt[k]++;
					}
				}
				memcpy(f, tmp, sizeof(f));
			}
			for(int j = 1; j <= 10; j++){
				printf("%s%d%s", (j==1)? "":" ", cnt[j], (j==10)? "\n":"");
			}
		}
	}
	return 0;
}
