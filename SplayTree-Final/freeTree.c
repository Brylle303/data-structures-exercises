void freeTree(Node *root)
{
    if(root)
    {
        freeTree(root->leftNode);
        freeTree(root->rightNode);
        free(root);
    }
}
