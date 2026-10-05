int countCharPosition(char* str1) {
    int count = 0;
    for (int i = 0; str1[i] != '\0'; i++) {
        if ((str1[i] == 'a' + i) || (str1[i] == 'A' + i)) {
            count++;
        }
    }
    return count;
}