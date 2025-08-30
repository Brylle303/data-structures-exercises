void deleteNode(Node **root, int key)
{
    if(!(*root))
    {
        printf("TREE IS EMPTY");
        getch();
        return;
    }
    Node *temp = searchNode(root, key);

    if (temp && key == temp->data)
    {
        system("cls");
        printf("[+]Splaying %d...", key);
        animateTree(root, temp);
        displayTree(*root);
        printf("(!) Press Space to Continue...");
        getch();
        system("cls");
        printf("[+]Deleting %d...\n", (*root)->data);
        Node *leftSubtree = (*root)->leftNode;
        Node *rightSubtree = (*root)->rightNode;
        free(*root);
        *root = NULL;
        printf("[+] Splaying from left subtree...");
        displayTree(leftSubtree);
        printf("(!) Press Space to Continue...");
        getch();
        system("cls");
        printf("[+] Splaying from right subtree...");
        displayTree(rightSubtree);
        printf("(!) Press Space to Continue...");
        getch();
        system("cls");
        if(leftSubtree)
        {
            leftSubtree->parentNode = NULL;
            Node *maxNode = findLargest(leftSubtree);
            printf("[+]Splaying %d from left subtree...\n", maxNode->data);
            animateTree(&leftSubtree, maxNode);
            system("cls");
            printf("[+]Joining left and right subtrees...\n");
            maxNode->rightNode = rightSubtree;
            if(rightSubtree)
            {
                rightSubtree->parentNode = maxNode;
            }
            *root = maxNode;

        }else
        {
            *root = rightSubtree;
            if(rightSubtree)
            {
                rightSubtree->parentNode = NULL;
            }
        }
        displayTree(*root);
        printf("(!) Press Space to Continue...");
        getch();
    }else
    {
        printf("[+]Node %d not found, splaying last accessed node...", key);
        if (temp) animateTree(root, temp);
    }
    displayTree(*root);
    printf("(!) Press Space to Continue...");
    getch();
}
