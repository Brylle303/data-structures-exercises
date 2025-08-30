Node* buildTree(int values[], int n, int order) {
    if (n <= 0)
        return NULL;

    Node *root = createNode(values[0], order);
    Node **queue = (Node**)malloc(n * sizeof(Node*));
    if (!queue) {
        printf("Malloc Failed");
        exit(EXIT_FAILURE);
    }
    int front = 0, rear = 0;
    queue[rear++] = root;

    int index = 1;
    while (front < rear && index < n) {
        Node *current = queue[front++];
        for (int i = 0; i < order && index < n; i++) {
            Node *child = createNode(values[index++], order);
            current->children[current->childCnt++] = child;
            queue[rear++] = child;
        }
    }
    free(queue);
    return root;
}
