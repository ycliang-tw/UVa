#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
int KMP_init(const char *str)
{
	int i = 1, j = 0;
	int prefix[100] = {};
	
	while(str[i]){
		while(j > 0 && str[j] != str[i])
			j = prefix[j-1];
		if(str[j] == str[i])
			j++;
		prefix[i] = j, i++;
	}
	return j;
}
int main()
{	
	int test_case;
	scanf("%d", &test_case);
	while(test_case--){
		char str[100] = {};
		scanf("%s", str);
		int len = strlen(str);
		int prefix_suffix_len_when_last_element = KMP_init(str);
		int num = prefix_suffix_len_when_last_element;
		
		if(len%(len - num) == 0){
			printf("%d\n", len - num);
		}else{
			printf("%d\n", len);
		}
		if(test_case){
			puts("");
		}
	}
	return 0;
}
