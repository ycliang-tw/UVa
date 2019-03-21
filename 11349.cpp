#include <stdio.h>
#define MAX 105

long long int arr[MAX*MAX];

int main(){
	int ncase;
	while(~scanf("%d\n", &ncase)){
		for(int i = 1; i <= ncase; i++){
			int lside, sym_flag = 1, cnt;
			scanf("N = %d", &lside);
			cnt = lside*lside;
			for(int j = 0; j < cnt; j++){
				scanf("%lld", &arr[j]);		
			}
			for(int j = 0; j < (cnt + 1)/2; j++){
				if(arr[j] != arr[cnt-j-1] || arr[j] < 0){
					sym_flag = 0;
				}
			}
			printf("Test #%d: %symmetric.\n", i, (sym_flag == 1)? "S" : "Non-s");
			getchar();
		}
	}
	return 0;
}
