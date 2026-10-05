int isPalindrome(int num) {
    char str[20];
    sprintf(str, "%d", num);
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return 0;
        }
    }
    return 1;
}
int previousPalindrome(int num) {
    for (int i = num - 1; i > 0; i--) {
        if (isPalindrome(i)) {
            return i;
        }
    }
    return -1;
}