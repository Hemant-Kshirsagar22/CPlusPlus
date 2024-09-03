#include <stdio.h>

int main(void)
{
	if (__STDC_VERSION__ == 201710L)
		printf("version : C 18\n");
	else if (__STDC_VERSION__ == 201112L)
		printf("version : C 11\n");
	else if (__STDC_VERSION__ == 199901L)
		printf("version : C 99\n");
	else if (__STDC_VERSION__ == 199409L)
		printf("version : C 89\n");
	else
		printf("pre-standard C\n");

	return(0);
}