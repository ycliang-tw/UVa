#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define maxn 105

int less(const char *s, int start, int ans)	// return 1 if s[start] < s[ans]
{
	int len = strlen(s);
	for(int i = 0; i < len; i++){
		if(s[ (start+i)%len ] != s[ (ans+i)%len ]){
			return s[ (start+i)%len ] < s[ (ans+i)%len ];
		}
	}
	return 0;
}

int main()
{	
	int num;
	char str[maxn] = {};
	while(~scanf("%d", &num)){
		while(num--){
			scanf("%s", str);
			int ans_pos = 0;
			int len = strlen(str);
			for(int i = 1; i < len; i++){
				if( less(str, i, ans_pos) ){
					ans_pos = i;
				}
			}

			for(int i = 0; i < len; i++){
				putchar(str[ (i+ans_pos)%len ]);
			}
			puts("");
		}
	}
	return 0;
}
