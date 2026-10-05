typedef struct Dictionary {
    char *key;
    int value;
    struct Dictionary *next;
} Dictionary;
void insert(Dictionary **head, const char *key, int value) {
    Dictionary *new_node = (Dictionary *)malloc(sizeof(Dictionary));
    new_node->key = strdup(key);
    new_node->value = value;
    new_node->next = *head;
    *head = new_node;
}
Dictionary *mergeDict(Dictionary *d1, Dictionary *d2) {
    Dictionary *result = NULL;
    Dictionary *current = d1;
    while (current != NULL) {
        insert(&result, current->key, current->value);
        current = current->next;
    }
    current = d2;
    while (current != NULL) {
        insert(&result, current->key, current->value);
        current = current->next;
    }
    return result;
}