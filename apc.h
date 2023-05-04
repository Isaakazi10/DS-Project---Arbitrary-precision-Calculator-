#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef int data_t;

typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
} Dlist;

int creating_LL(Dlist **head, Dlist **tail, char *argv);
void check(Dlist ***head, int *Flag);
int add(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
int sub(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
int mul(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
int divi(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
void print(Dlist *headR);
int big_small(int *Flag1, int *Flag2, Dlist ***head1, Dlist ***tail1, Dlist ***head2, Dlist ***tail2);

#endif
