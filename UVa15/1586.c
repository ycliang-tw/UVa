#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{	
	int num;
	scanf("%d", &num);	

	while(num--){

		char fml[105] = {};
		char ch[4] = {'C', 'H', 'O', 'N'};
		double w[4] = {12.01, 1.008, 16.00, 14.01};

		scanf("%s", fml);

		double weight = 0.0;
		
		for(int i = 0; fml[i]; i++){

			int n = 0; 
			double nw = 0.0;

			for(int j = 0; j < 4; j++){
				
				if(fml[i] == ch[j]){
					nw = w[j];
					while( isdigit(fml[i+1]) ){
						int tmp = fml[++i] - '0';
						n = n*10 + tmp;
					}
					if(n == 0)	n = 1;
					weight += (n * nw);
//					printf("i %d, char %c, j %d, nw %lf, n %d, weight %lf\n", i, fml[i], j, nw, n, weight);
				}
			}

		}

		printf("%.3lf\n", weight);
	}
	return 0;
}
