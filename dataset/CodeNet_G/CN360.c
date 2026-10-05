void swapChars(char *s, int i) {
    char temp = s[i];
    s[i] = s[i + 1];
    s[i + 1] = temp;
}
char *lexicographicallySmallestString(char *s, int k) {
    int len = strlen(s);
    int swaps;
    for (int i = 0; i < len && k > 0; i++) {
        int minIndex = i;
        for (int j = i + 1, swaps = 0; j < len && swaps < k; j++, swaps++) {
            if (s[j] < s[minIndex]) {
                minIndex = j;
            }
        }
        for (int j = minIndex; j > i; j--) {
            swapChars(s, j - 1);
            k--;
        }
    }
    return s;
}
