/*
458 - The Decoder
2015-09-10
*/
#include<stdio.h>
int main(){
	char s[256];
	while (1==scanf("%s",s)) {
		char *t = s;
		for (; *t; t++) {
			*t -= 7;
		}
		puts(s);
	}
	return 0;
}
