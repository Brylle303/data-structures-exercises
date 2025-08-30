void heapifyDownMin(HeapNode* node)
{
    while (node) {
        HeapNode* smallest = node;
        if (node->left && node->left->value < smallest->value) smallest = node->left;
        if (node->right && node->right->value < smallest->value) smallest = node->right;
        if (smallest != node) {
            int temp = node->value;
            node->value = smallest->value;
            smallest->value = temp;
            node = smallest;
        } else break;
    }
}
