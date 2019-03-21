#include <stdio.h>
#include <math.h>
int main(){
	int ncase;
	while( ~scanf("%d", &ncase) ){
		while(ncase--){
			int nplayer, ith;
			double p;
			scanf("%d %lf %d", &nplayer, &p, &ith);
			if(p == 0.0000){
				puts("0.0000");
				continue;
			}
//			printf("%d %lf %d\n", nplayer, p, ith);
			double ans = p * pow( (1.0 - p), (ith - 1)) / (1.0 - pow(( 1.0-p ), nplayer));
			printf("%.4f\n", ans);
		}
	}
	return 0;
}
