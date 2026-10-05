void tupleStrInt(const char* testStr, int* result, int* size) {
    char buffer[256];
    strncpy(buffer, testStr + 1, strlen(testStr) - 2);
    buffer[strlen(testStr) - 2] = '\0';
    char* token;
    *size = 0;
    token = strtok(buffer, ", ");
    while (token != NULL) {
        result[(*size)++] = atoi(token);
        token = strtok(NULL, ", ");
    }
}