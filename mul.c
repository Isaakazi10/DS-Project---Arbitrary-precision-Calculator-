/*
******************************************************************************************************************************************************************
Title			: Multiplication
Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
Prototype		: int multiplication(Dlist **head1, Dlist *ttail, Dlist **head2, Dlist **tail2, Dlist *tempP);
Input Parameters	: head1: Pointer to the first node of the first double linked list.
					: ttail: Pointer to the last node of the first double linked list.
					: head2: Pointer to the first node of the second double linked list.
					: tail2: Pointer to the last node of the second double linked list.
					: headR: Pointer to the first node of the resultant double linked list.
Output			: Status (SUCCESS / FAILURE)
******************************************************************************************************************************************************************
*/

#include "apc.h"

// mul function defination
int mul(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR)
{
	// Initialization of variables used in this program.
	int Flag1 = 0, Flag2 = 0, count = 0, carry = 0;
	Dlist *tempP = NULL, *tempN = NULL, *headP = NULL;

	// Calling check function.
	check(&head1, &Flag1);
	check(&head2, &Flag2);

	// While tail2 is not equal to head2 or tail2 is equal to head2 keep running the loop.
	while (((*head2) != (*tail2)) || (*tail2) == (*head2))
	{
		// for i is less than count make make a node whose data should be zero
		for (int i = 0; i < count; i++)
		{
			// Creating new_node and Updating pointers of nodes to NULL.
			Dlist *new_node = malloc(sizeof(Dlist));
			new_node->next = NULL;
			new_node->prev = NULL;

			// Updating data in new node.
			new_node->data = 0;

			// If tempN pointer is equal to NULL update the tempN and tempP pointers to new_node.
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

		// If head2 is not equal to tail2 or head2 is equal to tail2 then execute if-statement
		if ((*head2) != (*tail2) || (*head2) == (*tail2))
		{
			// Storing tail1 is store in temp pointer ttail.
			Dlist *ttail = *tail1;

			// while ttail is not equal to NULL keep running the loop
			while (ttail != NULL)
			{
				// Creating new_node with a size of structure Dlist
				Dlist *new_node = malloc(sizeof(Dlist));
				new_node->next = NULL;
				new_node->prev = NULL;

				// If carry is less than 10 then store carry in new_node data and make carry 0.
				if ((carry = ((ttail)->data * (*tail2)->data) + carry) < 10)
				{
					new_node->data = carry;
					carry = 0;
				}
				// Else carry mod of 10 should be stored in new_node data and make carry div of 10.
				else
				{
					new_node->data = carry % 10;
					carry = carry / 10;
				}

				// If tempN pointer is equal to NULL update the tempN and tempP pointers to new_node.
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

				// Update the ttail pointer to previous node
				ttail = (ttail)->prev;
			}
			// Update the tail2 pointer to previous node.
			*tail2 = (*tail2)->prev;
		}

		// while carry is greater than zero.
		while (carry > 0)
		{
			// Creating new_node with a size of structure Dlist
			Dlist *new_node = malloc(sizeof(Dlist));
			new_node->next = NULL;
			new_node->prev = NULL;

			// If carry is greater than equal to 10 then execute if-statement else store carry in new_node data.
			if (carry >= 10)
			{
				// carry mod of 10 is store in new_node data.
				new_node->data = carry % 10;
				// carry div by 10 is stored in carry.
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

		// tempP is not equal to NULL keep running the loop.
		while (tempP != NULL)
		{
			// if headR is equal to NULL then store assign tempN to headR and tempP to headP.
			if (*headR == NULL)
			{
				*headR = tempN;
				headP = tempP;
				break;
			}
			else
			{
				// If headt is equal to NULL then carry is equal to tempP data plus carry
				if (headt == NULL)
				{
					carry = tempP->data + carry;
				}
				else
				{
					// else carry is equal to headt data plus tempP data +carry
					carry = headt->data + tempP->data + carry;
				}

				// if tempP is not equal to NULL and headt is not equal to NULL then execute if statement
				if (tempP != NULL && headt == NULL)
				{
					// Create a new_node
					Dlist *new_node = malloc(sizeof(Dlist));
					new_node->next = *headR;
					new_node->prev = NULL;
					(*headR)->prev = new_node;
					*headR = (*headR)->prev;

					// If carry is less store carry in new_node and make carry to zero
					if (carry < 10)
					{
						new_node->data = carry;
						carry = 0;
					}
					else
					{
						// carry mod of 10 is store in new_node data.
						new_node->data = carry % 10;
						// carry div by 10 is stored in carry.
						carry = carry / 10;
					}
				}
				else
				{
					// If carry is greater than equal to 10 then execute if-statement else store carry in headt data.
					if (carry >= 10)
					{
						// carry mod of 10 is store in new_node data.
						headt->data = carry % 10;
						// carry div by 10 is stored in carry.
						carry = carry / 10;
					}
					else
					{
						headt->data = carry;
						carry = 0;
					}
				}
			}

			// Update tempP pointer to previous node
			tempP = tempP->prev;

			// if headt is not equal to NULL Update headt pointer.
			if (headt != NULL)
			{
				headt = headt->prev;
			}
		}

		// while carry is greater than zero keep running the loop.
		while (carry > 0)
		{
			// Creating a new_node to hold the data.
			Dlist *new_node = malloc(sizeof(Dlist));
			new_node->next = NULL;
			new_node->prev = NULL;

			// If carry is greater than equal to 10 then execute if-statement else store carry in new_node data.
			if (carry >= 10)
			{
				// carry mod of 10 is store in new_node data.
				new_node->data = carry % 10;

				// carry div by 10 is stored in carry.
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

		// If tail2 is equal to NULL then break the loop.
		if (*tail2 == NULL)
		{
			break;
		}

		// Update the tempP and tempN pointers to NULL and count++.
		tempP = tempN = NULL;
		count++;
	}
	if (((Flag1 == 1) && (Flag2 == 0)) || ((Flag1 == 0) && (Flag2 == 1)))
	{
		// if headR data is equal to zero then return SUCCESS.
		if ((*headR)->data == 0)
		{
			return SUCCESS;
		}

		// Assign new_node with ascii value of 45 which is character '-'
		Dlist *new_node = malloc(sizeof(Dlist));
		new_node->prev = NULL;
		new_node->data = '-';
		new_node->next = *headR;
		(*headR)->prev = new_node;
		*headR = (*headR)->prev;
	}
	return SUCCESS;
}