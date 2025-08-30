void rotateRight(Node *x)
{
    Node *y = x->leftNode;
    if (!y) return;

    x->leftNode = y->rightNode;
    if (y->rightNode != NULL)
        y->rightNode->parentNode = x;

    y->parentNode = x->parentNode;

    if (x->parentNode != NULL)
    {
        if (x == x->parentNode->leftNode)
            x->parentNode->leftNode = y;
        else
            x->parentNode->rightNode = y;
    }

    y->rightNode = x;
    x->parentNode = y;
}
