void displayList(Node* head) {
    Node* temp = head;
    printf("Displaying list of items:\n");
    for(int identifier = 1; temp != NULL; temp = temp->next) {
        printf("- %s\n", temp->data);
    }
}