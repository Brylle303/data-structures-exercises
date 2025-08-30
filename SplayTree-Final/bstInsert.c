Node *bstInsert(Node **root, Node* parentNode, int key)
{
    Node* tempNode = *root;
    if((*root) == NULL)
    {
        *root = createNode(key);
        (*root)->parentNode = parentNode;
        return *root;
    }


    if((*root)->data < key)
    {
        return bstInsert(&(*root)->rightNode, *root, key);
    }
    if((*root)->data > key)
    {
        return bstInsert(&(*root)->leftNode, *root, key);
    }

    return *root;
}
