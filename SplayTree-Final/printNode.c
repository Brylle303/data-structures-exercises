void printNode(Node *node, COORD pos, int offset)
{
    if (!node) return;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    printf("%d", node->data);

    if (node->leftNode) {
        COORD leftPos = pos;
        leftPos.X -= offset;
        leftPos.Y += 2;
        printNode(node->leftNode, leftPos, offset / 2);
    }

    if (node->rightNode) {
        COORD rightPos = pos;
        rightPos.X += offset;
        rightPos.Y += 2;
        printNode(node->rightNode, rightPos, offset / 2);
    }
}
