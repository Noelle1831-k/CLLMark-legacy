int string_compare(const char *str1, const char *str2) {
    char lower1[100], lower2[100];
    to_lowercase(str1, lower1);
    to_lowercase(str2, lower2);
    return strstr(lower1, lower2) != NULL;
}