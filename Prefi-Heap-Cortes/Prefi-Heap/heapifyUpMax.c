void heapifyUpMax(HeapNode* node)
{
    while(node->parent && node->data > node->parent->data)
    {
        int temp = node->data;
        node->data = node->parent->data;
        node->parent->data = temp;
        node = node->parent;
        heapifyCount++;
    }
}
