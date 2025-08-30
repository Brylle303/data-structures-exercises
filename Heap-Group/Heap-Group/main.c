#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct HeapNode
{
    int value;
    struct HeapNode *left, *right, *parent;

} HeapNode;

HeapNode *minRoot = NULL, *maxRoot = NULL;
int nodeCount = 0;

void gotoxy(int x, int y);
HeapNode* createNode(int value, HeapNode* parent);
HeapNode* insertLevelOrder(HeapNode* root, int value, HeapNode** inserted);
void printHeapTree(HeapNode* node, int x, int y, int offset);
void printHeaps();
void heapifyUpMin(HeapNode* node);
void heapifyUpMax(HeapNode* node);
void insert(int value);
void heapifyDownMin(HeapNode* node);
void heapifyDownMax(HeapNode* node);
void getLastNode(HeapNode* root, int index, int target, HeapNode** last);
void deleteRoot();
void addNodes();



int main()
{
    int choice;
    do {
        system("cls");
        printf("=== HEAP MAIN MENU ===\n");
        printf("[1] Add new nodes\n[2] Delete a node\n[3] Exit\n\nChoice? ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Try again.\n");
            Sleep(1000);
            continue;
        }
        fflush(stdin);
        switch (choice) {
            case 1: addNodes(); break;
            case 2: printf("DELETE"); break;
            case 3: printf("Exiting...\n"); break;
            default:
                printf("Invalid choice. Try again.\n");
                Sleep(1000);
        }
    } while (choice != 3);
    return 0;
}

void addNodes()
{
    char input[256];
    printf("Insert values to add (comma-separated): ");
    fflush(stdin);
    fgets(input, sizeof(input), stdin);
    char *token = strtok(input, ", ");
    while (token) {
        int val;
        if (sscanf(token, "%d", &val) == 1) {
            insert(val);
        } else {
            printf("\nInvalid input detected: %s", token);
        }
        token = strtok(NULL, ", ");
    }
}

HeapNode* createNode(int value, HeapNode* parent)
{
    HeapNode* newNode = (HeapNode*)malloc(sizeof(HeapNode));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    newNode->parent = parent;
    return newNode;
}

void getLastNode(HeapNode* root, int index, int target, HeapNode** last)
{
    if (!root) return;
    if (index == target) {
        *last = root;
        return;
    }
    getLastNode(root->left, 2 * index + 1, target, last);
    getLastNode(root->right, 2 * index + 2, target, last);
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void heapifyUpMax(HeapNode* node)
{
    while (node->parent && node->value > node->parent->value) {
        int temp = node->value;
        node->value = node->parent->value;
        node->parent->value = temp;
        node = node->parent;
    }
}

void insert(int value)
{
    HeapNode *insertedMax = NULL;
    maxRoot = insertLevelOrder(maxRoot, value, &insertedMax);
    heapifyUpMax(insertedMax);
    nodeCount++;
    printHeaps();
}

HeapNode* insertLevelOrder(HeapNode* root, int value, HeapNode** inserted)
{
    if (!root) {
        *inserted = createNode(value, NULL);
        return *inserted;
    }
    HeapNode* queue[MAX_SIZE];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        HeapNode* temp = queue[front++];
        if (!temp->left) {
            temp->left = createNode(value, temp);
            *inserted = temp->left;
            return root;
        } else queue[rear++] = temp->left;
        if (!temp->right) {
            temp->right = createNode(value, temp);
            *inserted = temp->right;
            return root;
        } else queue[rear++] = temp->right;
    }
    return root;
}

void printHeaps()
{
    //system("cls");
    gotoxy(40, 0); printf("A. MIN HEAP");
    printHeapTree(minRoot, 40, 2, 16);
    gotoxy(40, 12); printf("B. MAX HEAP");
    printHeapTree(maxRoot, 40, 14, 16);
}

void printHeapTree(HeapNode* node, int x, int y, int offset)
{
    if (!node) return;
    gotoxy(x, y);
    printf("%d", node->value);
    if (node->left) {
        gotoxy(x - offset / 2, y + 1);
        printf("/");
        printHeapTree(node->left, x - offset, y + 2, offset / 2);
    }
    if (node->right) {
        gotoxy(x + offset / 2, y + 1);
        printf("\\");
        printHeapTree(node->right, x + offset, y + 2, offset / 2);
    }

}


