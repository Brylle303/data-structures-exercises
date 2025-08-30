#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "genTree.h"
#include "printExtInt.c"
#include "printParent.c"
#include "printChild.c"
#include "printSiblings.c"
#include "freeTree.c"
#include "buildTree.c"
#include "createNode.c"


int main()
{
    int order;
    char userChoice;
    char inputLine[100];
    int values[100];
    int count = 0;

    printf("===GENERAL TREE ADT===\n");
    printf("----------------------\n");
    printf("[!]Input values: ");

    fgets(inputLine, sizeof(inputLine), stdin);

    inputLine[strcspn(inputLine, "\n")] = '\0';
    char *exclam = strchr(inputLine, '!');
    if (exclam != NULL)
    {
        *exclam = '\0';
    }

    char *token = strtok(inputLine, ",");
    while (token != NULL)
    {
        if (strlen(token) > 0) {
            values[count++] = atoi(token);
        }
        token = strtok(NULL, ",");
    }

    do {
        printf("\n[!]Input outdegree: ");

        if (scanf("%d", &order) != 1)
        {
            fprintf(stderr, "Invalid outdegree input.\n");
            return EXIT_FAILURE;
        }
        getchar();

        printf("\nGeneral Tree Information:\n");

        Node *root = buildTree(values, count, order);

        printInternalExternal(root);
        printParent(root);
        printChild(root);
        printSiblings(root);

        freeTree(root);

        printf("\n\n[!]Repeat Process? (Y/N): ");
        userChoice = getchar();
        while(getchar() != '\n');

    } while (userChoice == 'Y' || userChoice == 'y');

    return 0;
}
