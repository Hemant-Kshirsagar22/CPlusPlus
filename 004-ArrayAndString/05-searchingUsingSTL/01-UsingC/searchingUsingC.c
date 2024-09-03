#include<stdio.h>
#include <stdlib.h>

int main(void)
{
	int compare(const void *, const void *);
	int data[] = { 1, 2, 3, 4, 5 };
	int key = 3;
	
	// key ptr,array ptr,no of elements,sizeof single element,func to compare ptr
	if (bsearch(&key, data, 5, sizeof(int), compare))
	{
		printf("found !!!\n");
	}
	else
	{
		printf("Not Found !!!\n");
	}
}

int compare(const void *key, const void *mid)
{
	
	if (*(int *)key < *(int *)mid)
		return(-1);
	else if (*(int *)key > *(int *)mid)
		return(1);
	else
		return(0);
}
