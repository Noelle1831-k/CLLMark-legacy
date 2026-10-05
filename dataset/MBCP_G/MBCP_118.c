char** stringToList(const char* str, int* count) {
    int capacity = 10;
    char** list = (char**)malloc(capacity * sizeof(char*));
    *count = 0;
    char* token = strtok(strdup(str), " ");
    while (token) {
        if (*count >= capacity) {
            capacity *= 2;
            list = (char**)realloc(list, capacity * sizeof(char*));
        }
        list[(*count)++] = token;
        token = strtok(NULL, " ");
    }
    return list;
}