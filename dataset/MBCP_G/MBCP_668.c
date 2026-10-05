char* replace(char* str, char* chr) {
    int n = strlen(str);
    int m = strlen(chr);
    if (m == 0) return str;
    char *result = (char *)malloc((n + 1) * sizeof(char));
    int index = 0;
    int i = 0;
    while (i < n) {
        if (strncmp(&str[i], chr, m) == 0) {
            result[index++] = chr[0];
            while (i < n && strncmp(&str[i], chr, m) == 0) {
                i += m;
            }
        } else {
            result[index++] = str[i++];
        }
    }
    result[index] = '\0';
    return result;
}