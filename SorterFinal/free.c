void freeList(Node *head)
{
    Node *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
