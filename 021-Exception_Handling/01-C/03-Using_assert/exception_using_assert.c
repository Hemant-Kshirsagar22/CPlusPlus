#include <stdio.h>
#include <assert.h>

int numberOne = 0;
int numberTwo = 0;
int result = 0;

int main(void)
{
	printf("Enter First Number : ");
	scanf("%d",&numberOne);

	printf("Enter Second Number : ");
	scanf("%d",&numberTwo);

	assert(numberTwo != 0); // if this becomes false then it will terminate the program if it true it just ignore this line
	
	result = numberOne / numberTwo;

	printf("%d / %d = %d\n",numberOne,numberTwo,result);

	return(0);
}
