#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

typedef struct Node
{
    int key;
    int height;

    struct node *left;
    struct node *right;


}Node;


Node* createNode(int data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

int findHeight(Node* root)
{
    if (root == NULL)
    {
        return -1;
    }

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void checkTreeBalance(Node* root)
{
    if(findHeight(root) >= 2)
    {

    }
}


void gotoxy(int x, int y)
{
    COORD coord = {0,0};
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
    Node *root = NULL;

    printf("Loading AVL Tree... ");
    for(int i=0; i <= 100; i++)
    {
        system("cls");
        gotoxy(40,10);
        printf("Loading AVL Tree... %d%%", i);
        Sleep(20);

    }
    Sleep(1000);
    system("cls");
    gotoxy(45,10);
    printf("(!) Success!");
    Sleep(1500);

    printf("\n===AVL TREE PROGRAM===");
    printf("\n[1] INSERT");
    printf("\n[2] EDIT");
    printf("\n[3] DELETE");
    printf("\n[4] SEARCH");
    printf("\n[5] EXIT");


    return 0;
}
