void animateTree(Node **root, Node *splayNode)
{
    displayTree(*root);
    printf("(!) Press Space to Continue...");
    getch();
    while (splayNode->parentNode != NULL)
    {
        Node *p = splayNode->parentNode;
        Node *g = p->parentNode;

        if (g == NULL)
        {

            if (p->leftNode == splayNode)
            {
                rotateRight(p);
                system("cls");
            }
            else
            {
                rotateLeft(p);
                system("cls");
            }
        }
        else if (g->leftNode == p && p->leftNode == splayNode)//if zig zig
        {

            rotateRight(g);
            system("cls");
            displayTree(*root);
            printf("(!) Press Space to Continue...");
            getch();
            rotateRight(p);
            system("cls");
            displayTree(*root);
            printf("(!) Press Space to Continue...");
            getch();
        }
        else if (g->rightNode == p && p->rightNode == splayNode)//if zag zag
        {

            rotateLeft(g);
            system("cls");
            rotateLeft(p);
            system("cls");
            displayTree(*root);
            printf("(!) Press Space to Continue...");
            getch();
        }
        else if (g->leftNode == p && p->rightNode == splayNode)//if zig zag
        {

            rotateLeft(p);
            system("cls");
            displayTree(*root);
            printf("(!) Press Space to Continue...");
            getch();
            rotateRight(g);
            system("cls");
        }
        else if (g->rightNode == p && p->leftNode == splayNode)//if zag zig
        {

            rotateRight(p);
            system("cls");
            displayTree(*root);
            printf("(!) Press Space to Continue...");
            getch();
            rotateLeft(g);
            system("cls");
        }


        while ((*root)->parentNode != NULL)
            *root = (*root)->parentNode;


        system("cls");
    }
}
