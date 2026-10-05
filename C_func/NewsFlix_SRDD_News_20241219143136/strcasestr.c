char *strcasestr(const char *haystack, const char *needle) {
    if (!haystack || !needle) return NULL;
    char *lower_haystack = strdup(haystack);
    char *lower_needle = strdup(needle);
    to_lowercase(lower_haystack);
    to_lowercase(lower_needle);
    char *result = strstr(lower_haystack, lower_needle);
    free(lower_haystack);
    free(lower_needle);
    return result ? (char *)(haystack + (result - lower_haystack)) : NULL;
}