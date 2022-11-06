#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)

void divide(char* str)
{
	if (strlen(str) < 1)
	{
		return;
	}

	char str3[51];
	char* strP = str;
	int len = strlen(strP);
	char* strD;
	strD = str;
	strD = strD + len / 2;
	int half = strD - strP;
	strncpy(str3, strP, half);
	str3[half] = NULL;
	printf("%s\n", str3);

	divide(str3);

}

int main_2()
{
	char str[100];
	char str2[51];
	printf("Enter a string\n");
	gets(str);

	int strLength = strlen(str);
	char* ptr1;
	char* ptr2;
	ptr1 = str;
	ptr2 = str;
	printf("%s\n", ptr1);
	ptr2 = ptr2 + strLength / 2;
	printf("%s\n", ptr2);

	int halfstring = ptr2 - ptr1;
	strncpy(str2, str, halfstring);
	str2[halfstring] = NULL;
	printf("%s\n", str2);
	divide(str2);

	return 0;
}