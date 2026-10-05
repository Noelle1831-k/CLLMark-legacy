char** extractValues(const char* text, int* count) {
    int length = strlen(text);
    int capacity = 10;
    *count = 0;
    char** result = (char**)malloc(capacity * sizeof(char*));
    const char* current = text;
    while ((current = strchr(current, '"')) != NULL) {
        ++current;
        const char* end = strchr(current, '"');
        if (!end) break;
        int size = end - current;
        char* value = (char*)malloc((size + 1) * sizeof(char));
        strncpy(value, current, size);
        value[size] = '\0';
        if (*count >= capacity) {
            capacity *= 2;
            result = (char**)realloc(result, capacity * sizeof(char*));
        }
        result[(*count)++] = value;
        current = end + 1;
    }
    return result;
}