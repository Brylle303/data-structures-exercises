void rotateLeft(Node *x)
{
    Node *y = x->rightNode;
    if (!y) return;

    x->rightNode = y->leftNode;
    if (y->leftNode != NULL)
    {
        y->leftNode-> parentNode = x;
    }

    y->parentNode = x->parentNode;

    if (x->parentNode != NULL)
    {
        if (x == x->parentNode->leftNode)
            x->parentNode->leftNode = y;
        else
            x->parentNode->rightNode = y;
    }

    y->leftNode = x;
    x->parentNode = y;
}
