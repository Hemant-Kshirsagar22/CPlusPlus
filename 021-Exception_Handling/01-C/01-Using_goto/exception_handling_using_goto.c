#include <stdio.h>

int numberOne = 0;
	
int main(void)
{
	printf("Enter The Number : ");
	scanf("%d",&numberOne);

	if(numberOne % 2 == 0)
	{
		goto EvenNumberException;
	}
	else
	{
		goto OddNumberException;
	}	

	EvenNumberException:
		printf("This Is Even Number\n");
		return(0);
	


	OddNumberException:
		printf("This is Odd Number\n");
		return(0);

	return(0);
}



