void reverseStringList(char* stringList[], int size) {
    for (int i = 0; i < size; i++) {
        int len = strlen(stringList[i]);
        for (int j = 0; j < len / 2; j++) {
            char temp = stringList[i][j];
            stringList[i][j] = stringList[i][len - j - 1];
            stringList[i][len - j - 1] = temp;
        }
    }
}