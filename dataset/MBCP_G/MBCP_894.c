void floatToTuple(const char *str, double *result, int *size) {
    char *token;
    char *input = strdup(str); 
    const char *delimiter = ", ";
    int count = 0;
    token = strtok(input, delimiter);
    while (token != NULL) {
        result[count++] = atof(token);
        token = strtok(NULL, delimiter);
    }
    *size = count;
    free(input);
}