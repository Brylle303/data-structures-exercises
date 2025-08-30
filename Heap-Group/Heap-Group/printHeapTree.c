void printHeapTree(HeapNode* node, int x, int y, int offset)
{
    if (!node) return;
    gotoxy(x, y);
    printf("%d", node->value);
    if (node->left) {
        gotoxy(x - offset / 2, y + 1);
        printf("/");
        printHeapTree(node->left, x - offset, y + 2, offset / 2);
    }
    if (node->right) {
        gotoxy(x + offset / 2, y + 1);
        printf("\\");
        printHeapTree(node->right, x + offset, y + 2, offset / 2);
    }
}
