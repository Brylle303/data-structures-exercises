void heapifyUpMax(HeapNode* node)
{
    while (node->parent && node->value > node->parent->value) {
        int temp = node->value;
        node->value = node->parent->value;
        node->parent->value = temp;
        printHeaps();
        node = node->parent;
    }
}
