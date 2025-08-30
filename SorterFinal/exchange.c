void bubbleSort(Node **head, bool ascending)
{
    if (*head == NULL) return;

    bool swapped;
    Node *ptr, *last = NULL;

    do {
        swapped = false;
        ptr = *head;

        while (ptr->next != last) {
            if ((ascending && ptr->data > ptr->next->data) ||
                (!ascending && ptr->data < ptr->next->data)) {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = true;
            }
            ptr = ptr->next;
        }
        last = ptr;
        printList(*head);
    } while (swapped);
}
