void extractString(char *str[], int size, int length, char *result[], int *count) {
    *count = 0;
    for (int i = 0; i < size; i++) {
        if (strlen(str[i]) == length) {
            result[*count] = str[i];
            (*count)++;
        }
    }
}