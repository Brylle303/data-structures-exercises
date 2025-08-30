void deleteFunc(Node **root, int key)
{
    deleteNode(root, key);
    system("cls");
    displayTree(*root);
    printf("Deletion Successful");
}
