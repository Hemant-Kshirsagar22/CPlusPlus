#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int compare(const void *, const void *);

	int i = 0;
	int data[] = { 32,71,12,45,26 };
	
	//   start ptr, elements, size of single element,compare function pointer

	qsort(data, 5, sizeof(int), compare);

	for (i = 0; i < 5; i++)
		printf("%d ", data[i]);

	return(0);
}

int compare(const void *numberOne, const void *numberTwo)
{
	return(*(int *)numberOne < *(int *)numberTwo);
}
