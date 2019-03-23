#include <stdio.h>

int main(){
	int row, col, ncase = 1;
	while(scanf("%d %d", &row, &col) && (row && col)){
		int field[102][102] = {};
		for(int i = 1; i <= row; i++){
			char input[102] = {};
			scanf("%s", input);
			for(int j = 1; j <= col; j++){
				if(input[j-1] == '*'){
					field[i][j] = -9;
					field[i-1][j-1]++;
					field[i-1][j]++;
					field[i-1][j+1]++;
					field[i][j-1]++;
					field[i][j+1]++;
					field[i+1][j-1]++;
					field[i+1][j]++;
					field[i+1][j+1]++;
				}
			}
		}
		if(ncase != 1)	puts("");
		printf("Field #%d:\n", ncase++);
		for(int i = 1; i <= row; i++){
			for(int j = 1; j <= col; j++){
				if(field[i][j] < 0)
					printf("%c", '*');
				else
					printf("%d", field[i][j]);
			}
			puts("");
		}
	}

	return 0;
}
