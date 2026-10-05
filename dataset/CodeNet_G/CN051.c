int calculateDifference(char digits[]) {
    char max_digits[9], min_digits[9];
    int max_number, min_number;
    snprintf(max_digits, 9, "%s", digits);
    qsort(max_digits, 8, sizeof(char), (int(*)(const void*, const void*))strcmp);
    snprintf(min_digits, 9, "%s", digits);
    qsort(min_digits, 8, sizeof(char), (int(*)(const void*, const void*))strcmp_reverse);
    max_number = atoi(max_digits);
    min_number = atoi(min_digits);
    return max_number - min_number;
}
int strcmp_reverse(const char *a, const char *b) {
    return (*b - *a);
}