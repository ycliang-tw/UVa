#include <stdio.h>

int main(){
	int clndr[13][33] = {};
	clndr[4][4] = clndr[6][6] = clndr[8][8] = clndr[10][10] = clndr[12][12] = clndr[3][7] = 1;
	clndr[1][10] = clndr[2][21] = clndr[5][9] = clndr[9][5] = clndr[7][11] = clndr[11][7] = 1;

	int ncase;
	while( ~scanf("%d", &ncase) ){
		while(ncase--){
			int i, cal, month, date;
			scanf("%d %d", &month, &date);
			for(i = 1; clndr[month][i] != 1; i++);
//			printf("%d / %d ==  %d\n", month, i, clndr[month][i]);
			cal = date - i;
//			printf("cal = %d\n", cal);
			if(cal % 7 == 0){
				puts("Monday");
			}else if(cal % 7 == 1 || cal % 7 == -6){
				puts("Tuesday");
			}else if(cal % 7 == 2 || cal % 7 == -5){
				puts("Wednesday");
			}else if(cal % 7 == 3 || cal % 7 == -4){
				puts("Thursday");
			}else if(cal % 7 == 4 || cal % 7 == -3){
				puts("Friday");
			}else if(cal % 7 == 5 || cal % 7 == -2){
				puts("Saturday");
			}else{
				puts("Sunday");
			}
//			printf("%s\n", cal(month, date))
		}
	}
	return 0;
}
