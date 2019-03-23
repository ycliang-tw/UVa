#include <iostream>
using namespace std;

#define SIZE 100001

struct mapping{
	int x;
	int y;
}beehive[SIZE + 1];

void make_mapping(){
	beehive[1].x = 0, beehive[1].y = 0;
	int nowx = 0, nowy = 0, step;

	for(int circle = 1, index = 2; index <= SIZE; circle++){
		for(step = 1; index <= SIZE && step <= circle; index++, step++ ){		// downward
			beehive[index].x = nowx, beehive[index].y = ++nowy;
		}
		for(step = 1; index <= SIZE && step < circle; index++, step++){			// downward left, not in the first circle
			beehive[index].x = --nowx, beehive[index].y = ++nowy;
		}
		for(step = 1; index <= SIZE && step <= circle; index++, step++){		// upward left
			beehive[index].x = --nowx, beehive[index].y = nowy;
		}
		for(step = 1; index <= SIZE && step <= circle; index++, step++){		// upward
			beehive[index].x = nowx, beehive[index].y = --nowy;
		}
		for(step = 1; index <= SIZE && step <= circle; index++, step++){		// upward right 
			beehive[index].x = ++nowx, beehive[index].y = --nowy;
		}
		for(step = 1; index <= SIZE && step <= circle; index++, step++){		// downward left
			beehive[index].x = ++nowx, beehive[index].y = nowy;
		}
		
	}
}

int main(){
	int input;
	make_mapping();
	while(cin >> input){
		cout << beehive[input].x << " " << beehive[input].y << endl;
	}
	return 0;
}
