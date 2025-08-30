void selectionSort(Node **head, bool ascending)
{
    if (*head == NULL) return;

    Node *current = *head;
    while (current) {
        Node *minMax = current;
        Node *ptr = current->next;

        while (ptr) {
            if ((ascending && ptr->data < minMax->data) ||
                (!ascending && ptr->data > minMax->data)) {
                minMax = ptr;
            }
            ptr = ptr->next;
        }


        if (minMax != current) {
            int temp = current->data;
            current->data = minMax->data;
            minMax->data = temp;
        }

        printList(*head);
        current = current->next;
    }
}
