#include "apc.h"

void check(Dlist ***head, int *Flag)
{
    if ((**head)->data == '+' || (**head)->data == '-')
    {
        if (((**head)->data) == '-')
        {
            *Flag = 1;
        }

        **head = (**head)->next;
        free((**head)->prev);
        (**head)->prev = NULL;
    }
}

int big_small(int *Flag1, int *Flag2, Dlist ***head1, Dlist ***tail1, Dlist ***head2, Dlist ***tail2)
{
    int count1 = 0, count2 = 0;
    Dlist *temp1 = **head1;
    Dlist *temp2 = **head2;

    while (temp1 != NULL)
    {
        count1++;
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        count2++;
        temp2 = temp2->next;
    }

    if (count1 > count2)
    {
        ;
    }
    else if (count1 < count2)
    {
        int temp = *Flag1;
        *Flag1 = *Flag2;
        *Flag2 = temp;

        Dlist *tem1 = **head1;
        **head1 = **head2;
        **head2 = tem1;

        Dlist *tem2 = **tail1;
        **tail1 = **tail2;
        **tail2 = tem2;
    }
    else
    {
        temp1 = **head1;
        temp2 = **head2;

        while ((temp1 != NULL) || (temp1 == NULL))
        {
            if (temp1->data > temp2->data)
            {
                break;
            }
            else if (temp1->data < temp2->data)
            {
                int temp = *Flag1;
                *Flag1 = *Flag2;
                *Flag2 = temp;

                Dlist *tem1 = **head1;
                **head1 = **head2;
                **head2 = tem1;

                Dlist *tem2 = **tail1;
                **tail1 = **tail2;
                **tail2 = tem2;

                break;
            }
            else
            {

                temp1 = temp1->next;
                temp2 = temp2->next;
                if (temp1 == NULL)
                {
                    return -1;
                }
            }
        }
        return 0;
    }
}