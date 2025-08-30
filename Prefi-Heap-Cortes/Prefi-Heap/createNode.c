HeapNode* createNode(int value)
{
    HeapNode *newNode = (HeapNode*)malloc(sizeof(HeapNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;

    return newNode;
}
