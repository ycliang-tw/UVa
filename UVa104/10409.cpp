#include <stdio.h>

struct die{
	int t, n, e, s, w, b;
};

int main(){
	int rolls;
	while( scanf("%d", &rolls) && rolls ){
		char input[10] = {};
		struct die a;
		a.t = 1, a.b = 6, a.n = 2, a.s = 5, a.w = 3, a.e = 4;
		/*
		struct die a = {
			.t = 1,
			.b = 6,
			.n = 2,
			.s = 5,
			.w = 3,
			.e = 4
		};
		*/
//		printf("%d %d %d %d %d %d\n", a.t, a.n, a.w, a.e, a.s, a.b);
		getchar();
		for(int i = 0; i < rolls; i++){
			fgets(input, sizeof(input), stdin);
			int tmp = 0;
			if(input[0] == 'n'){
				tmp = a.n, a.n = a.t, a.t = a.s, a.s = a.b, a.b = tmp;
			}else if(input[0] == 'e'){
				tmp = a.e, a.e = a.t, a.t = a.w, a.w = a.b, a.b = tmp;
			}else if(input[0] == 'w'){
				tmp = a.w, a.w = a.t, a.t = a.e, a.e = a.b, a.b = tmp;
			}else if(input[0] == 's'){
				tmp = a.s, a.s = a.t, a.t = a.n, a.n = a.b, a.b = tmp;
			}
		}
		printf("%d\n", a.t);
	}
	return 0;
}
