int isReverse(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 != len2) return 0;
    for (int i = 0; i < len1; i++) {
        if (str1[i] != str2[len1 - i - 1]) {
            return 0;
        }
    }
    return 1;
}
int countReversePairs(char **testList, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (isReverse(testList[i], testList[j])) {
                count++;
            }
        }
    }
    return count;
}