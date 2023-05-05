#include "apc.h"

// Defination of print function
void print(Dlist *headR)
{
    // while headR is not equalt o NULL or headR is equal to NULL
    while (headR != NULL || headR == NULL)
    {
        // if headR data is equal to 45 then execute if statement
        if (headR->data == 45)
        {
            printf("%c", headR->data);
            headR = headR->next;
            continue;
        }

        printf("%d", (headR)->data);
        headR = headR->next;

        // if headR is equal to NULL then break the loop.
        if (headR == NULL)
        {
            break;
        }
    }
}