char** countVariable(int a, int b, int c, int d, int *size) {
    int i, count = 0;
    char *letters[] = {"p", "q", "r", "s"};
    int counts[] = {a, b, c, d};
    for (i = 0; i < 4; i++) {
        if (counts[i] > 0) {
            count += counts[i];
        }
    }
    char **result = malloc(count * sizeof(char*));
    int k = 0;
    for (i = 0; i < 4; i++) {
        if (counts[i] > 0) {
            for (int j = 0; j < counts[i]; j++) {
                result[k] = malloc((strlen(letters[i]) + 1) * sizeof(char));
                strcpy(result[k++], letters[i]);
            }
        }
    }
    *size = count;
    return result;
}
