void freeTree(Node *root)
{
    if (root == NULL)
        return;
    for (int i = 0; i < root->childCnt; i++) {
        freeTree(root->children[i]);
    }
    free(root->children);
    free(root);
}
