Node* createNode(int key)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(!newNode)
    {
        printf("Allocation Error: 001X_createNode");
    }

    else
    {
        newNode->data = key;
        newNode->parentNode = NULL;
        newNode->leftNode = NULL;
        newNode->rightNode = NULL;
    }

    return newNode;

}
