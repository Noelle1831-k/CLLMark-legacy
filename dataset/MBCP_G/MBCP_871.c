int areRotations(const char *string1, const char *string2) {
    if (strlen(string1) != strlen(string2)) {
        return 0;
    }
    int len = strlen(string1);
    char *concat = (char *)malloc((2 * len + 1) * sizeof(char));
    if (!concat) {
        return 0;
    }
    strcpy(concat, string1);
    strcat(concat, string1);
    int result = strstr(concat, string2) != NULL;
    free(concat);
    return result;
}