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
