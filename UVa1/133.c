#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int N; // number of people
int a[25];  // indication of person in queue or not 

// return new_pos
int go(int pos, int direction, int steps)
{
    while(steps--){
        do{
           pos = ( pos + direction + N -1 ) % N + 1;
//           printf("pos: %d\n", pos);
        }while(a[pos] == 0);
    }
    return pos;
}

int main()
{	
    int k, m;
    while(scanf("%d %d %d", &N, &k, &m) == 3){
        if(N == 0 && k == 0 && m == 0) break;
        for(int i = 1; i <= N; i++){
            a[i] = 1;
        }
        int left = N;   // number of people left
        int pos1 = N, pos2 = 1; // first round ccw: 1->4, but second: 4->8 
                                // (the spaces between are different, 
                                // let pos1 == N(CCW), pos2 == 1(CW), making the spaces between the same)
        while(left)
        {
            pos1 = go(pos1, 1, k);
            pos2 = go(pos2, -1, m);

            printf("%3d", pos1);
            left -= 1;

            if(pos1 != pos2){
                printf("%3d", pos2);
                left -= 1;
            }

            a[pos1] = a[pos2] = 0;
            if(left)    printf(",");
        }
        puts("");
    }
	return 0;
}
