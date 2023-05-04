#include "apc.h"

int creating_LL(Dlist **head, Dlist **tail, char *argv)
{
    // Initializing of count;
    int i = -1;

    if (argv[0] == 0)
    {
        printf("Invalid Input : Enter Number");
        return FAILURE;
    }

    // whiele argv is not equal to NULL.
    while (argv[++i] != 0)
    {
        if ((argv[i] == '+') || (argv[i] == '-'))
        {
            Dlist *new_node = malloc(sizeof(Dlist));
            // Make new_node POINTERS equal to NULL
            new_node->next = new_node->prev = NULL;

            new_node->data = argv[0];

            // Update the *head and *tail.
            *head = *tail = new_node;
            continue;
        }
        // If char within string is less than ascii value of 48 and more than 58 then return FAILURE.
        else if ((argv[i] < 48) || (argv[i] > 57))
        {
            printf("Invalid Input : Only Numbers\n");
            return FAILURE;
        }

        // Making new_node for storing of data.
        Dlist *new_node = malloc(sizeof(Dlist));
        if (new_node == NULL)
        {
            return FAILURE;
        }

        // Store the data in the node.
        new_node->data = argv[i] - 48;

        // If *head and *tail are equal to NULL then
        if ((*head == NULL) && (*tail == NULL))
        {
            // Make new_node POINTERS equal to NULL
            new_node->next = new_node->prev = NULL;

            // Update the *head and *tail.
            *head = *tail = new_node;
        }
        else
        {
            // Update the new_node POINTERs with node->prev with *tail and next with NULL
            new_node->prev = *tail;
            new_node->next = NULL;

            // Store address of new_node in previous node
            (*tail)->next = new_node;

            // Update *tail pointer to next node.
            *tail = (*tail)->next;
        }
    }
    return SUCCESS;
}