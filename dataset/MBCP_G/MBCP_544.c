void flattenTuple(char *output, char tuples[][3][10], int sizes[], int n) {
    char buffer[500] = "";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            strcat(buffer, tuples[i][j]);
            if (i != n - 1 || j != sizes[i] - 1) {
                strcat(buffer, " ");
            }
        }
    }
    strcpy(output, buffer);
}