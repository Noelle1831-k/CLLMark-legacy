char** convert(const char* str, int* size) {
    char** list = (char**)malloc(10 * sizeof(char*));
    char* token;
    char* str_copy = strdup(str);
    int index = 0;
    token = strtok(str_copy, " ");
    while (token != NULL) {
        list[index] = (char*)malloc((strlen(token) + 1) * sizeof(char));
        strcpy(list[index], token);
        index++;
        token = strtok(NULL, " ");
    }
    *size = index;
    free(str_copy);
    return list;
}