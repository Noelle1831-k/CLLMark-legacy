typedef struct Node {
    int *data;
    int size;
    struct Node *next;
} Node;
Node* create_node(int *data, int size) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        new_node->data[i] = data[i];
    }
    new_node->size = size;
    new_node->next = NULL;
    return new_node;
}
void append_node(Node **head, int *data, int size) {
    Node *new_node = create_node(data, size);
    if (!*head) {
        *head = new_node;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}
void join_tuples(int tuples[][2], int length, Node **result) {
    for (int i = 0; i < length;) {
        int start = tuples[i][0];
        int temp[2] = {start, tuples[i][1]};
        int n = 2;
        ++i;
        while (i < length && tuples[i][0] == start) {
            temp[n++] = tuples[i][1];
            ++i;
        }
        append_node(result, temp, n);
    }
}
void print_result(Node *result) {
    Node *current = result;
    while (current != NULL) {
        for (int i = 0; i < current->size; ++i) {
            printf("%d", current->data[i]);
            if (i < current->size - 1) printf(", ");
        }
        printf("\n");
        current = current->next;
    }
}
void free_nodes(Node *head) {
    Node *current = head;
    while (current != NULL) {
        free(current->data);
        Node *next = current->next;
        free(current);
        current = next;
    }
}