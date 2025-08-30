Node *searchNode(Node **root, int key)
{
    if((*root) == NULL)
    {
        return NULL;
    }

    if((*root)->data == key)
    {
        return *root;
    }

    if(key > (*root)->data)
    {
        Node *right = searchNode(&(*root)->rightNode, key);
        if(right)
        {
            return right;
        }
    }

    if(key < (*root)->data)
    {
        Node *left = searchNode(&(*root)->leftNode, key);
        if(left)
        {
            return left;
        }
    }

    return *root;
}
