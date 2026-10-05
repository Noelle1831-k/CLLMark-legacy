void process_string(char *str, int n) {
    char current[201] = {0}, next[201] = {0};
    int len, i, j, count, digit;
    strcpy(current, str);
    for (int k = 0; k < n; k++) {
        len = strlen(current);
        next[0] = '\0';
        for (i = 0; i < len; i++) {
            count = 1;
            digit = current[i];
            while (i + 1 < len && current[i + 1] == digit) {
                count++;
                i++;
            }
            j = strlen(next);
            sprintf(&next[j], "%d%c", count, digit);
        }
        strcpy(current, next);
    }
    printf("%s\n", current);
}