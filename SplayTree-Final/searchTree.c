void searchTree(Node **root, int key)
{
    if(!(*root))
    {
        printf("\n(!) Tree/Subtree is empty!\n");
        getch();
        return;
    }
    Node *temp = searchNode(root, key);

    if (temp && key == temp->data)
    {
        printf("(!) Splaying node %d...", key);
        animateTree(root, temp);
    }else
    {
        printf("(!) Node %d not found, splaying last accessed node...", key);
        if (temp) animateTree(root, temp);
    }
    displayTree(*root);
    printf("(!) Press Space to Continue...");
    getch();
}
