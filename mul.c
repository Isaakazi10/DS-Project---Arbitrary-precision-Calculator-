/*******************************************************************************************************************************************************************
*Title			: Multiplication
*Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
*Prototype		: int multiplication(Dlist **head1, Dlist *ttail, Dlist **head2, Dlist **tail2, Dlist *tempP);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			:ttail: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int mul(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR)
{
	// To Store carry
	int Flag1 = 0, Flag2 = 0, count = 0;
	int carry = 0, temp = 0;
	Dlist *tempP = NULL, *tempN = NULL, *headP = NULL;

	check(&head1, &Flag1);
	check(&head2, &Flag2);

	// While
	while (((*head2) != (*tail2)) || (*tail2) == (*head2))
	{
		for (int i = 0; i < count; i++)
		{
			// Creating new_node and Updating pointers of nodes to NULL.
			Dlist *new_node = malloc(sizeof(Dlist));
			new_node->next = NULL;
			new_node->prev = NULL;

			// Updating data in new node.
			new_node->data = 0;

			if (tempN == NULL)
			{
				tempP = tempN = new_node;
			}
			else
			{
				tempN->prev = new_node;
				new_node->next = tempN;
				tempN = tempN->prev;
				tempN->prev = NULL;
			}
		}

		Dlist *headt = headP;
		if ((*head2) != (*tail2) || (*head2) == (*tail2))
		{
			Dlist *ttail = *tail1;
			while (ttail != NULL)
			{
				Dlist *new_node = malloc(sizeof(Dlist));
				new_node->next = NULL;
				new_node->prev = NULL;

				if ((carry = ((ttail)->data * (*tail2)->data) + carry) < 10)
				{
					new_node->data = carry;
					carry = 0;
				}
				else
				{
					new_node->data = carry % 10;
					carry = carry / 10;
				}

				if (tempN == NULL)
				{
					tempP = tempN = new_node;
				}
				else
				{
					tempN->prev = new_node;
					new_node->next = tempN;
					tempN = tempN->prev;
					tempN->prev = NULL;
				}

				ttail = (ttail)->prev;
			}
			*tail2 = (*tail2)->prev;
		}

		while (carry > 0)
		{
			Dlist *new_node = malloc(sizeof(Dlist));
			new_node->next = NULL;
			new_node->prev = NULL;

			if (carry >= 10)
			{
				new_node->data = carry % 10;
				carry = carry / 10;
			}
			else
			{
				new_node->data = carry;
				carry = 0;
			}
			tempN->prev = new_node;
			new_node->next = tempN;
			tempN = tempN->prev;
			tempN->prev = NULL;
		}

		while (tempP != NULL)
		{
			if (*headR == NULL)
			{
				*headR = tempN;
				headP = tempP;
				break;
			}
			else
			{
				if (headt == NULL)
				{
					carry = tempP->data + carry;
				}
				else
				{
					carry = headt->data + tempP->data + carry;
				}

				if (tempP != NULL && headt == NULL)
				{
					Dlist *new_node = malloc(sizeof(Dlist));
					new_node->next = *headR;
					new_node->prev = NULL;
					(*headR)->prev = new_node;
					*headR = (*headR)->prev;

					if (carry < 10)
					{
						new_node->data = carry;
						carry = 0;
					}
					else
					{
						new_node->data = carry % 10;
						carry = carry / 10;
					}
				}
				else
				{
					if (carry >= 10)
					{
						headt->data = carry % 10;
						carry = carry / 10;
					}
					else
					{
						headt->data = carry;
						carry = 0;
					}
				}
			}
			tempP = tempP->prev;
			if (headt != NULL)
			{
				headt = headt->prev;
			}
		}
		while (carry > 0)
		{
			Dlist *new_node = malloc(sizeof(Dlist));
			new_node->next = NULL;
			new_node->prev = NULL;

			if (carry >= 10)
			{
				new_node->data = carry % 10;
				carry = carry / 10;
			}
			else
			{
				new_node->data = carry;
				carry = 0;
			}
			tempN->prev = new_node;
			new_node->next = tempN;
			tempN = tempN->prev;
			tempN->prev = NULL;
		}

		if (*tail2 == NULL)
		{
			break;
		}

		tempP = tempN = NULL;
		count++;
	}
	if (((Flag1 == 1) && (Flag2 == 0)) || ((Flag1 == 0) && (Flag2 == 1)))
	{
		if ((*headR)->data == 0)
		{
			return SUCCESS;
		}

		Dlist *new_node = malloc(sizeof(Dlist));
		new_node->data = '-';
		new_node->next = *headR;
		(*headR)->prev = new_node;
		*headR = (*headR)->prev;
	}
	return SUCCESS;
}