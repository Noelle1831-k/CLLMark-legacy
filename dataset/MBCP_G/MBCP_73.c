#define MAX_TOKENS 100
char** multipleSplit(const char* input, int* count) {
    const char* delimiters = "\n*";
    char* copy = strdup(input);
    if (!copy) {
        *count = 0;
        return NULL;
    }
    char** result = (char**)malloc(MAX_TOKENS * sizeof(char*));
    if (!result) {
        free(copy);
        *count = 0;
        return NULL;
    }
    *count = 0;
    char* token = strtok(copy, delimiters);
    while (token != NULL && *count < MAX_TOKENS) {
        result[*count] = strdup(token);
        if (!result[*count]) {
            for (int i = 0; i < *count; i++) {
                free(result[i]);
            }
            free(copy);
            free(result);
            *count = 0;
            return NULL;
        }
        (*count)++;
        token = strtok(NULL, delimiters);
    }
    free(copy);
    return result;
}