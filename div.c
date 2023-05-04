/*******************************************************************************************************************************************************************
*Title			: Division
*Description		: This function performs division of two given large numbers and store the result in the resultant list.
*Prototype		: int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int divi(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR)
{
	// To Store borrow
	int Flag1 = 0, Flag2 = 0, count = 0;

	check(&head1, &Flag1);
	check(&head2, &Flag2);

	// While
	while ((*head1) != (*tail1))
	{
		int borrow = 0;
		Dlist *temp1 = *tail1, *temp2 = *tail2;

		while ((temp2)->prev != NULL)
		{
			temp1->data = temp1->data - borrow;
			borrow = 0;
			if (temp1->data < temp2->data)
			{
				temp1->data = temp1->data + 10;
				temp1->data = temp1->data - temp2->data;
				borrow = 1;
			}
			else
			{
				temp1->data = temp1->data - temp2->data;
			}
			temp1 = temp1->prev;
			temp2 = temp2->prev;

			if (temp1 == NULL && temp2 != NULL)
			{
				break;
			}
		}
		if (temp1 == NULL && temp2 != NULL)
		{
			break;
		}

		if (temp2->prev == NULL)
		{
			temp1->data = temp1->data - borrow;
			borrow = 0;
			if (temp1->data < temp2->data)
			{
				temp1->data = temp1->data + 10;
				temp1->data = temp1->data - temp2->data;
				borrow = 1;
			}
			else
			{
				temp1->data = temp1->data - temp2->data;
			}
		}

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

			borrow = 0;
		}
		else if ((temp1->prev == NULL) && (borrow == 1))
		{
			if (((Flag1 == 1) && (Flag2 == 1)) || ((Flag1 == 0) && (Flag2 == 0)))
			{
				printf("%d\n", count);
			}
			else
			{
				printf("%d\n", count);
			}
			return SUCCESS;
		}

		while (((*head1)->data == 0))
		{
			if ((*head1)->next == NULL)
			{
				break;
			}

			(*head1) = (*head1)->next;
			free((*head1)->prev);
			(*head1)->prev = NULL;
		}
		count++;
	}

	if (*head1 == *tail1)
	{
		int borrow = 0;
		Dlist *temp1 = *tail1, *temp2 = *tail2;

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
		else if (((*tail1)->prev == NULL) && ((*tail2)->prev != NULL))
		{
			;
		}
	}
	if (((Flag1 == 1) && (Flag2 == 1)) || ((Flag1 == 0) && (Flag2 == 0)))
	{
		printf("%d\n", count);
	}
	else
	{
		printf("-%d\n", count);
	}
	return SUCCESS;
}