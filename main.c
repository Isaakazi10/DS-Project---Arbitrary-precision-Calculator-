/**************************************************************************************************************************************************************
 *Title		: main function(Driver function)
 *Description	: This function is used as the driver function for the all the functions
 ***************************************************************************************************************************************************************/
#include "apc.h"

int main(int agrc, char **argv)
{
	// If argc is not equal to 4 then print Usage and return FAILURE.
	if (agrc != 4)
	{
		printf("Invalid Input");
		printf("Usage : ./output_file   6456   (Add:'+' Sub:'-' Mul:'x' Div:'/')    897\n");
		return FAILURE;
	}

	/* Declare the pointers */
	Dlist *head1, *tail1, *head2, *tail2, *headR;
	char operator=(*argv[2]);

	// Function for creating linked list
	creating_LL(&head1, &tail1, argv[1]);
	creating_LL(&head2, &tail2, argv[3]);

	printf("%s %s %s = ", argv[1], argv[2], argv[3]);
	switch (operator)
	{
	case '+':
		add(&head1, &tail1, &head2, &tail2, &headR);
		print(headR);
		break;
	case '-':
		sub(&head1, &tail1, &head2, &tail2, &headR);
		print(headR);
		break;
	case 'x':
		mul(&head1, &tail1, &head2, &tail2, &headR);
		print(headR);
		break;
	case '/':
		divi(&head1, &tail1, &head2, &tail2, &headR);
		break;
	default:
		printf("Invalid Input:-( Try again...\n");
		printf("Usage : ./output_file   6456   (Add:'+' Sub:'-' Mul:'x' Div:'/')    897\n");
		return FAILURE;
	}

	return SUCCESS;
}