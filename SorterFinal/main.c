#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "sorter.h"
#include "free.c"
#include "insert.c"
#include "newNode.c"
#include "print.c"
#include "selection.c"
#include "insertion.c"
#include "exchange.c"

int main()
{
    char input[20];
    char order;
    int value;

    Node *list1 = NULL, *list2 = NULL, *list3 = NULL;

    printf("===NUMBER SORTER===\n");
    printf("Enter numbers to sort (type '!' to stop):\n");

    while(1)
    {
        scanf("%s", input);
        if (input[0] == '!')
        {
            break;
        }


        if (sscanf(input, "%d", &value) == 1)
        {
            insertEnd(&list1, value);
            insertEnd(&list2, value);
            insertEnd(&list3, value);
        }
        else
        {
            printf("Invalid input. Please enter numbers or '!' to stop.\n");
        }
    }

    while (getchar() != '\n');

    printf("Sort [A]scending or [D]escending? A/D: ");
    scanf(" %c", &order);

    bool ascending = (order == 'A' || order == 'a');

    printf("\nSorting using Bubble Sort:\n");
    bubbleSort(&list1, ascending);

    printf("\nSorting using Selection Sort:\n");
    selectionSort(&list2, ascending);

    printf("\nSorting using Insertion Sort:\n");
    insertionSort(&list3, ascending);

    freeList(list1);
    freeList(list2);
    freeList(list3);

    printf("\nDone!\n");
    return 0;
}
