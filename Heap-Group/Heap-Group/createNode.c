HeapNode* createNode(int value, HeapNode* parent)
{
    HeapNode* newNode = (HeapNode*)malloc(sizeof(HeapNode));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    newNode->parent = parent;
    return newNode;
}
