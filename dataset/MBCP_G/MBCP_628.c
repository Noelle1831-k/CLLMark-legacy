void replaceSpaces(char* str) {
    int spaceCount = 0, i;
    int length = strlen(str);
    for (i = 0; i < length; i++) {
        if (str[i] == ' ') {
            spaceCount++;
        }
    }
    int newLength = length + spaceCount * 2;
    str[newLength] = '\0';
    for (i = length - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            str[newLength - 1] = '0';
            str[newLength - 2] = '2';
            str[newLength - 3] = '%';
            newLength -= 3;
        } else {
            str[newLength - 1] = str[i];
            newLength--;
        }
    }
}