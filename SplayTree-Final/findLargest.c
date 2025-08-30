Node *findLargest(Node *root)
{
    while(root->rightNode != NULL)
    {
        root = root->rightNode;
    }
    return root;
}
