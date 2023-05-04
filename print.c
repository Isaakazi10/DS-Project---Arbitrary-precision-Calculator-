#include "apc.h"

void print(Dlist *headR)
{
    while (headR->next != NULL)
    {
        if (headR->data == 45)
        {
            printf("%c", headR->data);
            headR = headR->next;
            continue;
        }

        printf("%d", (headR)->data);
        headR = headR->next;
    }
    if (headR->next == NULL)
    {
        printf("%d", (headR)->data);
    }
}