void displayList(Node* head) {
    Node* temp = head;
    printf("Displaying list of items:\n");
    while (temp != NULL) {
        printf("- %s\n", temp->data);
        temp = temp->next;
    }
}