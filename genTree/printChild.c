void printChild(Node *root)
{
    if (root == NULL) return;

    printf("\nChild Nodes: ");
    Node **queue = (Node **)malloc(MAX_VALUES * sizeof(Node *));
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear)
    {
        Node *current = queue[front++];

        if (current->childCnt > 0)
        {
            for (int i = 0; i < current->childCnt; i++)
            {
                printf("%d ", current->children[i]->data);
                queue[rear++] = current->children[i];
            }
        }
    }
    free(queue);
}
