#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXD 100
#define SPSH 10000

int r, c, n;
int sht[MAXD][MAXD], sht2[MAXD][MAXD] /* tmp sht */, ans[MAXD][MAXD], col[MAXD];

void del(char type)
{

}

void ins(char type)
{

}


int main()
{	
	int q
    char cmd[10] = {};
    
    while(scanf("%d%d%d", &r, &c, &n) == 3 && (r&c)){
        // init
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++){
                sht[i][j] = i*SPSH + j; // record original position
            }
        }
        // parse & execute command
        while(n--){
            scanf("%s", cmd);
            if(cmd[0] == 'E'){
                scanf();
            }else{
                // do something
                if(cmd[0] == 'D')
                    del(cmd[1]);
                else
                    ins(cmd[1]);
            }
        }
        // analyze result
        for(int i){
            for(int j){
            
            }
        }
        printf("Spreadsheet #%d\n", );

        // accept query
        scanf("%d", &q);
        while(q--){
            scanf("%d%d", );
            printf("Cell data in (%d,%d) ", );
            if()
                puts("GONE");
            else
                printf("move to (%d,%d)\n", );
        }
    }
	
    return 0;
}
