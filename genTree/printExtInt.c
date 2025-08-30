void printInternalExternal(Node *root)
{
    if (root == NULL) return;

    printf("\nInternal Nodes: ");
    Node **queue = (Node **)malloc(MAX_VALUES * sizeof(Node *));
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        Node *current = queue[front++];
        for (int i = 0; i < current->childCnt; i++)
        {
            queue[rear++] = current->children[i];
        }
        if (current->childCnt > 0)
        {
            printf("%d ", current->data);
        }
    }
    printf("\nExternal Nodes: ");

    front = 0;
    while (front < rear) {
        Node *current = queue[front++];
        if (current->childCnt == 0) {
            printf("%d ", current->data);
        }
    }
    printf("\n");
    free(queue);
}
