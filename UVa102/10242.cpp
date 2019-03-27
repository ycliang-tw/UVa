#include <stdio.h>

int main(){
	double ax[4] = {}, ay[4] = {};
	while( ~scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &ax[0], &ay[0], &ax[1], &ay[1], &ax[2], &ay[2], &ax[3], &ay[3]) ){
		int x, y;
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				if(i == j) continue;
				else if(ax[i] == ax[j] && ay[i] == ay[j]){
					x = i, y = j;
				}
			}
		}
//		printf("x == %d, y == %d\n", x, y);
		double tmp1 = 0.0, tmp2 = 0.0;
		for(int i = 0; i < 4; i++){
			if(i == x || i == y)
				continue;
			tmp1 += ax[i];
			tmp2 += ay[i];
		}
//		printf("tmp1 == %.3f, tmp2 == %.3f\n", tmp1, tmp2);
		double a4x = tmp1 - ax[x];
		double a4y = tmp2 - ay[y];
		printf("%.3lf %.3lf\n", a4x, a4y);
	}
	return 0;
}
