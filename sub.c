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

// sub function defination
int sub(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR)
{
	// Initialization of variables used in this program.
	int carry = 0, Flag1 = 0, Flag2 = 0, temp = 0, bism = 0, borrow = 0;

	// Calling check function.
	check(&head1, &Flag1);
	check(&head2, &Flag2);

	// Storing head1 pointer in temph for future comparing.
	Dlist *temph = *head1;

	// If (Flag1 == 1 and Flag2 == 0) or (Flag1 == 0 and Flag2 == 1) then execute if-statement
	if (((Flag1 == 0) && (Flag2 == 0)) || ((Flag1 == 1) && (Flag2 == 1)))
	{
		// Calling big_small Fucntion and if the function returns -1 then store 0 in new_node and return SUCCESSs.
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

	// While tail1 or tail2 is not equal to NULL or tail1 and tail2 is equal to NULL keep running the loop.
	while ((*tail1 != NULL) || (*tail2 != NULL) || (*tail1 == NULL) && (*tail2 == NULL))
	{
		// Creating a new_node to hold the data.
		Dlist *new_node = malloc(sizeof(Dlist));
		new_node->prev = NULL;
		new_node->next = NULL;

		// If (Flag1 == 0 and Flag2 == 0) or (Flag1 == 1 and Flag2 == 1) then execute if-statement else else-statement.
		if ((Flag1 == 1) && (Flag2 == 0) || ((Flag1 == 0) && (Flag2 == 1)))
		{
			// Algorithum for Subtracting the data.
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

			// If the temp is greater than 9 than make temp lesser than 10 by sub it with 10 and store that in new_node and make carry 1.
			if (temp > 9)
			{
				temp = temp - 10;
				new_node->data = temp;
				carry = 1;
			}
			// Directly store temp in new_node data and make carry 0;
			else
			{
				new_node->data = temp;
				carry = 0;
			}

			// Algorithum for connecting the nodes.
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

			// Update the node if the node is not equal to NULL
			if (*tail1 != NULL)
			{
				*tail1 = (*tail1)->prev;
			}
			if (*tail2 != NULL)
			{
				*tail2 = (*tail2)->prev;
			}

			// If both nodes (tail1 and tail2) are equal to NULL then break the loop.
			if ((*tail1 == NULL) && (*tail2 == NULL))
			{
				break;
			}
		}
		else
		{
			// Algorithum for adding the data.
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

			// If the temp is lesser than 0 than make temp greater than 10 by adding it with 10 and store that in new_node and make borrow 1.
			if (temp < 0)
			{
				temp = temp + 10;
				new_node->data = temp;
				borrow = 1;
			}
			// Directly store temp in new_node data and make borrow 0;
			else
			{
				new_node->data = temp;
				borrow = 0;
			}

			// Algorithum for connecting the nodes.
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

			// Update the node if the node is not equal to NULL
			if (*tail1 != NULL)
			{
				*tail1 = (*tail1)->prev;
			}
			if (*tail2 != NULL)
			{
				*tail2 = (*tail2)->prev;
			}

			// If both nodes (tail1 and tail2) are equal to NULL then break the loop.
			if ((*tail1 == NULL) && (*tail2 == NULL))
			{
				break;
			}
		}
	}

	// if tail1 and tail2 is equal to NULL and carry is equal to 1 then store that carry in new_node.
	if (((*tail1 == NULL) && (*tail2 == NULL)) && (carry == 1))
	{
		Dlist *new_node = malloc(sizeof(Dlist));
		new_node->data = carry;
		new_node->next = *headR;
		(*headR)->prev = new_node;
		*headR = (*headR)->prev;
	}

	// If Flag1 and Flag2 is equal to 1 or Flag1 is equal to 1 and Flag2 is equal to 0 then add '-' to new node.
	if (((Flag1 == 1) && (Flag2 == 1)) || ((Flag1 == 1) && (Flag2 == 0)))
	{
		// If data store in headR->data is zero then return SUCCESS
		if ((*headR)->data == 0)
		{
			return SUCCESS;
		}
		Dlist *new_node = malloc(sizeof(Dlist));
		new_node->prev = NULL;
		new_node->data = '-';
		new_node->next = *headR;
		(*headR)->prev = new_node;
		*headR = (*headR)->prev;
	}
	// If Flag1 and Flag2 is equal to 1 and temph is not equal to head1 then add '-' to new node.
	else if (((Flag1 == 0) && (Flag2 == 0)) && (temph != *head1))
	{
		Dlist *new_node = malloc(sizeof(Dlist));
		new_node->prev = NULL;
		new_node->data = '-';
		new_node->next = *headR;
		(*headR)->prev = new_node;
		*headR = (*headR)->prev;
	}

	// Return SUCCESS.
	return SUCCESS;
}
