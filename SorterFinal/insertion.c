void insertionSort(Node **head, bool ascending) {
    if (*head == NULL || (*head)->next == NULL) return;

    Node *sorted = NULL;
    Node *current = *head;

    while (current) {
        Node *next = current->next;
        if (sorted == NULL ||
           (ascending && current->data < sorted->data) ||
           (!ascending && current->data > sorted->data)) {
            current->next = sorted;
            sorted = current;
        } else {
            Node *temp = sorted;
            while (temp->next &&
                  ((ascending && temp->next->data < current->data) ||
                  (!ascending && temp->next->data > current->data))) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
        printList(sorted);
    }
    *head = sorted;
}
