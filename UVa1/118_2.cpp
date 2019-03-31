#include <stdio.h>

int main(){
	int ncol, nrow;
	int nx, ny;
	char f, ins[1000] = {}, table[55][55] = {};
	scanf("%d %d", &ncol, &nrow);
	while( scanf("%d %d %c", &nx, &ny, &f) == 3) {
		int flag = 0;
		scanf("%s", ins);
		for(int i = 0; ins[i]; i++){
			if(ins[i] == 'F'){
				switch(f) {
					case 'N': ny++; break;
					case 'E': nx++; break;
					case 'S': ny--; break;
					case 'W': nx--; break;
				}
			} else if(ins[i] == 'R') {
				switch(f) {
					case 'N': f = 'E'; break;
				    case 'E': f = 'S'; break;
			        case 'S': f = 'W'; break;
			        case 'W': f = 'N'; break;
				}
			} else{
				switch(f) {
					case 'N': f = 'W'; break;
				    case 'E': f = 'N'; break;
			        case 'S': f = 'E'; break;
			        case 'W': f = 'S'; break;
				}
			}
			if(nx < 0 || ny < 0 || nx > ncol || ny > nrow) {
				switch(f) {
					case 'N': ny--; break;
					case 'E': nx--; break;
					case 'S': ny++; break;
					case 'W': nx++; break;
				}
				if(table[nx][ny] == 1)	continue;
				flag = 1;
				table[nx][ny] = 1;
				break;
			}
		}
		printf("%d %d %c%s", nx, ny, f, (flag==0)? "\n":" LOST\n");
	}

	return 0;
}
