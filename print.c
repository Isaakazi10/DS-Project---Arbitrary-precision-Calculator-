#include "apc.h"

void print(Dlist *headR)
{
    while (headR != NULL || headR == NULL)
    {
        if (headR->data == 45)
        {
            printf("%c", headR->data);
            headR = headR->next;
            continue;
        }

        printf("%d", (headR)->data);
        headR = headR->next;
        if (headR == NULL)
        {
            break;
        }
    }
}