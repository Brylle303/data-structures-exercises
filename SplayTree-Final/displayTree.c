void displayTree(Node* root)
{
    if (!root)
    {
        printf("\n(!) Tree/Subtree is empty.\n");
        return;
    }

    COORD rootPos;
    rootPos.X = 146/2;
    rootPos.Y = 5;

    printNode(root, rootPos, 20);
    drawConnections(root, 146/2, 5, 20);

    COORD textPos = {0, 5 + 10};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), textPos);
}
