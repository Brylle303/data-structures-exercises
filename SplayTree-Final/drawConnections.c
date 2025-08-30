void drawConnections(Node *node, int x, int y, int offset)
{
    if (!node) return;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;

    if (node->leftNode) {
        pos.X = x - offset/2;
        pos.Y = y + 1;
        SetConsoleCursorPosition(hConsole, pos);
        printf("/");
        drawConnections(node->leftNode, x - offset, y + 2, offset/2);
    }

    if (node->rightNode) {
        pos.X = x + offset/2;
        pos.Y = y + 1;
        SetConsoleCursorPosition(hConsole, pos);
        printf("\\");
        drawConnections(node->rightNode, x + offset, y + 2, offset/2);
    }
}
