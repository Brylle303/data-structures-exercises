void printHeaps()
{
    //system("cls");
    gotoxy(40, 0); printf("A. MIN HEAP");
    printHeapTree(minRoot, 40, 2, 16);
    gotoxy(40, 12); printf("B. MAX HEAP");
    printHeapTree(maxRoot, 40, 14, 16);
}
