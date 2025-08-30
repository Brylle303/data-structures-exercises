#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <ctype.h>

#include "SplayTree.h"
#include "addNode.c"
#include "createNode.c"
#include "bstInsert.c"
#include "displayTree.c"
#include "printNode.c"
#include "drawConnections.c"
#include "animateTree.c"
#include "rotateLeft.c"
#include "rotateRight.c"
#include "freeTree.c"
#include "deleteFunc.c"
#include "deleteNode.c"
#include "findLargest.c"
#include "searchNode.c"
#include "searchTree.c"

void mainMenu();

int main()
{
    Node *root = NULL;
    int exitValue = 0;
    int choice;
    int key;

    while(!exitValue)
    {
        system("cls");
        printf("Splay Tree ADT v1.0\n");
        mainMenu();
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            system("cls");
            printf("Input value to INSERT!\nValue: ");
            scanf("%d", &key);
            while (getchar() != '\n');
            addNode(&root, key);
            break;
        case 2:
            system("cls");
            printf("Input value to DELETE!\nValue: ");
            scanf("%d", &key);
            while (getchar() != '\n');
            deleteFunc(&root, key);
            break;
        case 3:
            system("cls");
            printf("Input value to SEARCH!\nValue: ");
            scanf("%d", &key);
            while (getchar() != '\n');
            searchTree(&root, key);
            break;
        case 4:
            freeTree(root);
            printf("\n[!]EXITING PROGRAM...\n");

            return 0;
        }
    }

    return 0;
}

void mainMenu()
{
    printf("\n[1] Insert Node \n[2] Delete Node \n[3] Search Node \n[4] Exit");
    printf("\n\nCHOICE: ");

}



