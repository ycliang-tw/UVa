#include <stdio.h>
#include <string.h>

#define MAXD 100
#define SPSH 10000

int r, c, n;
int sht[MAXD][MAXD], sht2[MAXD][MAXD] /* tmp sht */, ans[MAXD][MAXD], cols[MAXD];

void copy(char type, int p, int q)
{
	if(type == 'R'){
		for(int i = 1; i <= c; i++){
			sht[p][i] = sht2[q][i];
		}
	}else{
		for(int i = 1; i <= r; i++){
			sht[i][p] = sht2[i][q];
		}
	}
}

void del(char type)
{
	memcpy(sht2, sht, sizeof(sht));
	int cnt = (type=='R')? r:c, cnt2 = 0;
	for(int i = 1; i <= cnt; i++){
		if(cols[i] != 1){
			copy(type, ++cnt2, i);
		}
	}
	if(type == 'R'){
		r = cnt2;
	}else{
		c = cnt2;
	}
}

void ins(char type)
{
	memcpy(sht2, sht, sizeof(sht));
	int cnt = (type=='R')? r:c, cnt2 = 0;
	for(int i = 1; i <= cnt; i++){
		if(cols[i] == 1){
			copy(type, ++cnt2, 0);
		}
		copy(type, ++cnt2, i);
	}
	if(type == 'R'){
		r = cnt2;
	}else{
		c = cnt2;
	}
}


int main()
{	
	int q, kase = 0;
	int r1, c1, r2, c2; // for EX command
    char cmd[10] = {};
   	memset(sht, 0, sizeof(sht));
    while(scanf("%d%d%d", &r, &c, &n) == 3 && r){
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
                scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
				int t = sht[r1][c1];
				sht[r1][c1] = sht[r2][c2], sht[r2][c2] = t;
            }else{
                // do something
				int a, x;
				scanf("%d", &a);
				memset(cols, 0, sizeof(cols));
				for(int i = 0; i < a; i++){
					scanf("%d", &x);
					cols[x] = 1;
				}
                if(cmd[0] == 'D')
                    del(cmd[1]);
                else
                    ins(cmd[1]);
            }
        }
		memset(ans, 0, sizeof(ans));
        // analyze result
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++){
            	ans[ sht[i][j]/SPSH  ][ sht[i][j]%SPSH ] = i*SPSH+j;
            }
        }
		if(kase>0) puts("");
        printf("Spreadsheet #%d\n", ++kase);

        // accept query
        scanf("%d", &q);
        while(q--){
            scanf("%d%d", &r1, &c1);
            printf("Cell data in (%d,%d) ", r1, c1);
            if(ans[r1][c1] == 0)
                puts("GONE");
            else
                printf("moved to (%d,%d)\n", ans[r1][c1]/SPSH, ans[r1][c1]%SPSH);
        }
    }
	
    return 0;
}
