char** splitList(const char* text, int* returnSize) {
    int len = strlen(text);
    int capacity = 10;
    int size = 0;
    char** result = (char**)malloc(capacity * sizeof(char*));
    int prevIndex = 0;
    for (int i = 1; i < len; i++) {
        if (isupper(text[i])) {
            int partLen = i - prevIndex;
            char* part = (char*)malloc((partLen + 1) * sizeof(char));
            strncpy(part, text + prevIndex, partLen);
            part[partLen] = '\0';
            if (size >= capacity) {
                capacity *= 2;
                result = (char**)realloc(result, capacity * sizeof(char*));
            }
            result[size++] = part;
            prevIndex = i;
        }
    }
    int partLen = len - prevIndex;
    char* part = (char*)malloc((partLen + 1) * sizeof(char));
    strncpy(part, text + prevIndex, partLen);
    part[partLen] = '\0';
    if (size >= capacity) {
        capacity += 1;
        result = (char**)realloc(result, capacity * sizeof(char*));
    }
    result[size++] = part;
    *returnSize = size;
    return result;
}
