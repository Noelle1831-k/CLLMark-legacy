void tupleToSet(char tuples[][10], int n, char result[][10], int *size) {
    int i, j;
    int found;
    *size = 0;
    for (i = 0; i < n; i++) {
        found = 0;
        for (j = 0; j < *size; j++) {
            if (strcmp(result[j], tuples[i]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(result[*size], tuples[i]);
            (*size)++;
        }
    }
}