/*
******************************************************************************************************************************************************************
Title			: Division
Description		: This function performs division of two given large numbers and store the result in the resultant list.
Prototype		: int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
Input Parameters	: head1: Pointer to the first node of the first double linked list.
					: tail1: Pointer to the last node of the first double linked list.
					: head2: Pointer to the first node of the second double linked list.
					: tail2: Pointer to the last node of the second double linked list.
					: headR: Pointer to the first node of the resultant double linked list.
Output			: Status (SUCCESS / FAILURE)
******************************************************************************************************************************************************************
*/

#include "apc.h"

// div function defination
int divi(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR)
{
	// Initialization of variables used in this program.
	int Flag1 = 0, Flag2 = 0, count = 0;

	// Calling check function.
	check(&head1, &Flag1);
	check(&head2, &Flag2);

	// While head1 is not equal to tail1 keep running the loop
	while ((*head1) != (*tail1))
	{
		// Initiaize a borrow variable and temp pointers to store tail1 and tail2 pointers
		int borrow = 0;
		Dlist *temp1 = *tail1, *temp2 = *tail2;

		// While temp2 is not equal to NULL keep running the loop.
		while ((temp2)->prev != NULL)
		{
			// Storing temp1 data minus borrow in temp1 data and borrow 0.
			temp1->data = temp1->data - borrow;
			borrow = 0;

			// If the temp1 data is lesser than temp2 data than make temp1 data greater than 10 by adding it with 10 and do temp1 data minus temp2 data store that in temp1 data and make borrow 1.
			if (temp1->data < temp2->data)
			{
				temp1->data = temp1->data + 10;
				temp1->data = temp1->data - temp2->data;
				borrow = 1;
			}
			// Do temp1 data minus temp2 data store that in temp1 data.
			else
			{
				temp1->data = temp1->data - temp2->data;
			}

			// Update the pointers temp1 and temp2 to previous node
			temp1 = temp1->prev;
			temp2 = temp2->prev;

			// if temp1 is equal to NULL and temp2 is not equal to NULL then break.
			if (temp1 == NULL && temp2 != NULL)
			{
				break;
			}
		}
		// if temp1 is equal to NULL and temp2 is not equal to NULL then break.
		if (temp1 == NULL && temp2 != NULL)
		{
			break;
		}

		// If temp2 prev is equal to NULL then execute if-statement
		if (temp2->prev == NULL)
		{
			// Storing temp1 data minus borrow in temp1 data and borrow 0.
			temp1->data = temp1->data - borrow;
			borrow = 0;

			// If the temp1 data is lesser than temp2 data than make temp1 data greater than 10 by adding it with 10 and do temp1 data minus temp2 data store that in temp1 data and make borrow 1.
			if (temp1->data < temp2->data)
			{
				temp1->data = temp1->data + 10;
				temp1->data = temp1->data - temp2->data;
				borrow = 1;
			}
			// Do temp1 data minus temp2 data store that in temp1 data.
			else
			{
				temp1->data = temp1->data - temp2->data;
			}
		}

		// if temp1 and temp2 are not equal to NULL and borrow is equal to 1 then store that borrow in new_node.
		if ((temp2->prev == NULL) && (temp1->prev != NULL) && (borrow == 1))
		{
			temp1->prev->data = temp1->prev->data - borrow;
			Dlist *temp = temp1;
			while (temp->prev->data < 0)
			{
				temp = temp->prev;
				temp->data = temp->data + 10;
				temp->prev->data = temp->prev->data - borrow;
			}
			// Make borrow zero.
			borrow = 0;
		}
		else if ((temp1->prev == NULL) && (borrow == 1))
		{
			// If Flag1 and Flag2 is equal to 1 or Flag1 is equal to 0 and Flag2 is equal to 0 then print count.
			if (((Flag1 == 1) && (Flag2 == 1)) || ((Flag1 == 0) && (Flag2 == 0)))
			{
				printf("%d\n", count);
			}
			// else print minus of count.
			else
			{
				printf("-%d\n", count);
			}
			// Return SUCCESS
			return SUCCESS;
		}

		// While head1 data is equal to 0 keep running the loop
		while (((*head1)->data == 0))
		{
			// If head1 next is equal to NULL then break the loop;
			if ((*head1)->next == NULL)
			{
				break;
			}

			// Update the head1 pointer to next node and free previous node and make head of prev NULL
			(*head1) = (*head1)->next;
			free((*head1)->prev);
			(*head1)->prev = NULL;
		}
		count++;
	}

	// if head1 is equal to tail1 then execute if-statement
	if (*head1 == *tail1)
	{
		// Initiaize a borrow variable and temp pointers to store tail1 and and tail2 pointers
		int borrow = 0;
		Dlist *temp1 = *tail1, *temp2 = *tail2;

		// if head1 data is equal to 0 do Nothing
		if ((*head1)->data == 0)
		{
			;
		}
		else if (((*tail1)->prev == NULL) && ((*tail2)->prev == NULL))
		{
			if ((*tail1)->data >= (*tail2)->data)
			{
				while ((*tail1)->data > 0)
				{
					(*tail1)->data = (*tail1)->data - (*tail2)->data;
					if ((*tail1)->data < 0)
					{
						break;
					}

					count++;
				}
			}
		}
		// iftail1 is equal to NULL and  tail2 prev is not equal to NULL then do nothing
		else if (((*tail1)->prev == NULL) && ((*tail2)->prev != NULL))
		{
			;
		}
	}
	// If Flag1 and Flag2 is equal to 1 or Flag1 is equal to 1 and Flag2 is equal to 0 then print count.
	if (((Flag1 == 1) && (Flag2 == 1)) || ((Flag1 == 0) && (Flag2 == 0)))
	{
		printf("%d\n", count);
	}
	else
	{
		// if count is equal to 0 print count
		if (count == 0)
		{
			printf("%d\n", count);
		}
		// else print minus of count.
		else
			printf("-%d\n", count);
	}
	return SUCCESS;
}