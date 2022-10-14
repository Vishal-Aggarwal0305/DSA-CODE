#include<stdio.h>
#include<string.h>
int count_unique_char(char* str) {

	int tempstr[200] = { 0 };
	int i, c = 0;
	for (i = 0; i < strlen(str); ++i) {
		tempstr[str[i]] = 1;
	}
	for (i = 0; i < 200; ++i) {
		c += tempstr[i];
	}
	return c;
}
int main() {
	char str[100];
	gets(str);
	if(count_unique_char(str) %2 == 0)
    printf("CHAT WITH HER!");
    else
    printf("IGNORE HIM!");
    return 0;
}