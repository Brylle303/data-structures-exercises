void printSiblings(Node *root)
{
    if (root == NULL) return;

    printf("\nSiblings: ");
    Node **queue = (Node **)malloc(MAX_VALUES * sizeof(Node *));
    int front = 0, rear = 0;
    queue[rear++] = root;

    printf("|");
    while (front < rear)
    {
        Node *current = queue[front++];

        if (current->childCnt > 1)
        {
            for (int i = 0; i < current->childCnt; i++) {
                printf("%d ", current->children[i]->data);
            }
            printf("|");
        }

        for (int i = 0; i < current->childCnt; i++)
        {
            queue[rear++] = current->children[i];
        }
    }
    free(queue);
}
