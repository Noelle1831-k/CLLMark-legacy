void combine(char *prefix, const char *str, int n, int k, char **result, int *count) {
    if (k == 0) {
        result[(*count)++] = strdup(prefix);
        return;
    }
    for (int i = 0; i < n; i++) {
        char newPrefix[MAX_LETTERS];
        snprintf(newPrefix, sizeof(newPrefix), "%s%c", prefix, str[i]);
        combine(newPrefix, str + i + 1, n - i - 1, k - 1, result, count);
    }
}