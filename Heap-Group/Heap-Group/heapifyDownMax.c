void heapifyDownMax(HeapNode* node)
{
    while (node) {
        HeapNode* largest = node;
        if (node->left && node->left->value > largest->value) largest = node->left;
        if (node->right && node->right->value > largest->value) largest = node->right;
        if (largest != node) {
            int temp = node->value;
            node->value = largest->value;
            largest->value = temp;
            node = largest;
        } else break;
    }
}
