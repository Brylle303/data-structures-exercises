Node* createNode(int value, int order)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Malloc Failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->childCnt = 0;
    newNode->children = (Node**)malloc(order * sizeof(Node*));
    if (!newNode->children) {
        printf("Malloc Failed");
        free(newNode);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < order; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}
