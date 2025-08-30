void addNode(Node **root, int key)
{
    Node* latestNode = bstInsert(root, NULL, key);
    animateTree(root, latestNode);
    displayTree(*root);
    printf("[DONE!] Tree after inserting %d:\n", key);
    getch();
}
