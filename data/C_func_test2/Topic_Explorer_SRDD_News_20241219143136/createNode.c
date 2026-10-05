Node* createNode(char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (! (NULL != newNode)) {
        printf("Memory allocation failed for new node.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}