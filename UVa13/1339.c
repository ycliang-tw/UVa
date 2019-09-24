#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{	
    char input1[110] = {}, input2[110] = {};

    while(scanf("%s %s", input1, input2) == 2){
        int in1[30] = {}, in2[30] = {}, cnt_flag[30] = {};
        int i = 0;
        for(i = 0; input1[i]; i++){
            in1[input1[i]-'A']++;
        }
        for(i = 0; input2[i]; i++){
            in2[input2[i]-'A']++;
        }
        for(i = 0; i < 30; i++){
            cnt_flag[in1[i]]++; cnt_flag[in2[i]]--;
        }
        for(i = 0; i < 30; i++){
            if(cnt_flag[i] != 0)
                break;
        }
        if(i != 30){
            puts("NO");
        }else{
            puts("YES");
        }
    
    }
	return 0;
}
