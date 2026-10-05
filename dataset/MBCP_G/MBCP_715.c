int* strToTuple(const char* str, int* size) {
    char* temp = strdup(str);
    char* token = strtok(temp, ", ");
    int* result = (int*)malloc(100 * sizeof(int)); 
    *size = 0;
    while (token != NULL) {
        result[*size] = atoi(token);
        (*size)++;
        token = strtok(NULL, ", ");
    }
    free(temp);
    return result;
}