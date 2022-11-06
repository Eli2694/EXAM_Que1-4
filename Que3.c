#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)

int add222(int num)
{

	printf("%d\n", num);
	return num != 100? add222(num + 1): 0;
}

int main_3()
{
	add222(1);
	return 0;
	
}