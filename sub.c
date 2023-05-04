/*******************************************************************************************************************************************************************
*Title			: Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int sub(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR)
{
	// Initialization of variables used in this program.
	int carry = 0, Flag1 = 0, Flag2 = 0, temp = 0, bism = 0, borrow = 0;

	check(&head1, &Flag1);
	check(&head2, &Flag2);

	Dlist *temph = *head1;

	if (((Flag1 == 0) && (Flag2 == 0)) || ((Flag1 == 1) && (Flag2 == 1)))
	{
		bism = big_small(&Flag1, &Flag2, &head1, &tail1, &head2, &tail2);
		if (bism == -1)
		{
			Dlist *new_node = malloc(sizeof(Dlist));
			new_node->data = 0;
			new_node->next = NULL;
			new_node->prev = NULL;
			*headR = new_node;
			return SUCCESS;
		}
	}

	// While
	while ((*tail1 != NULL) || (*tail2 != NULL) || (*tail1 == NULL) && (*tail2 == NULL))
	{
		Dlist *new_node = malloc(sizeof(Dlist));
		new_node->prev = NULL;
		new_node->next = NULL;

		if ((Flag1 == 1) && (Flag2 == 0) || ((Flag1 == 0) && (Flag2 == 1)))
		{
			if (*tail1 == NULL)
			{
				temp = (0 + (*tail2)->data) + carry;
			}
			else if (*tail2 == NULL)
			{
				temp = ((*tail1)->data + 0 + carry);
			}
			else
			{
				temp = ((*tail1)->data + (*tail2)->data) + carry;
			}

			if (temp > 9)
			{
				temp = temp - 10;
				new_node->data = temp;
				carry = 1;
			}
			else
			{
				new_node->data = temp;
				carry = 0;
			}

			if (*headR == NULL)
			{
				*headR = new_node;
				new_node->next = NULL;
			}
			else
			{
				(*headR)->prev = new_node;
				new_node->next = *headR;
				*headR = (*headR)->prev;
			}

			if (*tail1 != NULL)
			{
				*tail1 = (*tail1)->prev;
			}

			if (*tail2 != NULL)
			{
				*tail2 = (*tail2)->prev;
			}

			if ((*tail1 == NULL) && (*tail2 == NULL))
			{
				break;
			}
		}
		else
		{
			if (*tail1 == NULL)
			{
				temp = ((*tail2)->data) - borrow;
			}
			else if (*tail2 == NULL)
			{
				temp = ((*tail1)->data - borrow);
			}
			else
			{
				temp = ((*tail1)->data - (*tail2)->data) - borrow;
			}

			if (temp < 0)
			{
				temp = temp + 10;
				new_node->data = temp;
				borrow = 1;
			}
			else
			{
				new_node->data = temp;
				borrow = 0;
			}

			if (*headR == NULL)
			{
				*headR = new_node;
				new_node->next = NULL;
			}
			else
			{
				(*headR)->prev = new_node;
				new_node->next = *headR;
				*headR = (*headR)->prev;
			}

			if (*tail1 != NULL)
			{
				*tail1 = (*tail1)->prev;
			}

			if (*tail2 != NULL)
			{
				*tail2 = (*tail2)->prev;
			}

			if ((*tail1 == NULL) && (*tail2 == NULL))
			{
				break;
			}
		}
	}

	if (((*tail1 == NULL) && (*tail2 == NULL)) && (carry == 1))
	{
		Dlist *new_node = malloc(sizeof(Dlist));
		new_node->data = carry;
		new_node->next = *headR;
		(*headR)->prev = new_node;
		*headR = (*headR)->prev;
	}

	if ((Flag1 == 1) && (Flag2 == 1))
	{
		Dlist *new_node = malloc(sizeof(Dlist));
		new_node->prev = NULL;
		new_node->data = '-';
		new_node->next = *headR;
		(*headR)->prev = new_node;
		*headR = (*headR)->prev;
	}
	else if (((Flag1 == 1) && (Flag2 == 0)) || ((Flag1 == 0) && (Flag2 == 1)))
	{
		if (Flag1 == 1)
		{
			Dlist *new_node = malloc(sizeof(Dlist));
			new_node->prev = NULL;
			new_node->data = '-';
			new_node->next = *headR;
			(*headR)->prev = new_node;
			*headR = (*headR)->prev;
		}
	}
	else if ((Flag1 == 0) && (Flag2 == 0))
	{
		if (temph != *head1)
		{
			Dlist *new_node = malloc(sizeof(Dlist));
			new_node->prev = NULL;
			new_node->data = '-';
			new_node->next = *headR;
			(*headR)->prev = new_node;
			*headR = (*headR)->prev;
		}
	}

	return SUCCESS;
}
