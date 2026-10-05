int is_palindrome(const char *str) {
    int left = 0;
    int right = strlen(str) - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}
void count_palindromes() {
    char line[101];
    int count = 0;
    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = '\0';
        if (is_palindrome(line)) {
            count++;
        }
    }
    printf("%d\n", count);
}