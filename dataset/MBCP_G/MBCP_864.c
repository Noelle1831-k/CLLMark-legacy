int isPalindrome(const char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}
char **findPalindromes(char *texts[], int size, int *resultSize) {
    char **palindromes = (char **)malloc(size * sizeof(char *));
    *resultSize = 0;
    for (int i = 0; i < size; i++) {
        if (isPalindrome(texts[i])) {
            palindromes[*resultSize] = texts[i];
            (*resultSize)++;
        }
    }
    return palindromes;
}