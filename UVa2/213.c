#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int codetab[8][1<<8];

int readchar()
{
    while(1){
        int ch = getchar();
        if(ch != '\n' && ch != '\r')    return ch;
    }  
}
int convert2int(int len)
{
    int idx = 0;
    while(len--){
        idx = idx*2 + (readchar() - '0');
    }
    return idx;
}

int readcodes()
{
    memset(codetab, 0, sizeof(codetab));
    codetab[1][0] = readchar();
    for(int len = 2; len < 8; len++){
        for(int idx = 0; idx < (1<<len)-1; idx++){
            int ch = getchar();

            if(ch == EOF)   
                return 0;

            if(ch == '\n' || ch == '\r')
                return 1;

            codetab[len][idx] = ch;
        }
    }
    return 1;

}

void printcodes()
{
    for(int i = 1; i <= 7; i++){
        for(int j = 0; j < (1<<i) -1; j++){
            if(codetab[i][j] == 0)  return;
            printf("codetab[%d][%d] = %c\n", i, j, codetab[i][j]);
        }
    }
}


int main()
{	
    while(readcodes()){
//        printcodes();
        while(1){
            int len = convert2int(3);

//            printf("len: %d\\n", len);
            if(len == 0)    break;

            while(1){
                int code_idx = convert2int(len);
                int finish = (1<<len) -1;
//                printf("code_idx: %d\n", code_idx);
                if(code_idx == finish)    break;

                putchar(codetab[len][code_idx]);
            }

        }
        puts("");
    }	
	return 0;
}
