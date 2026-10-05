int asciiValueString(const char* str1) {
    if (str1 == NULL || strlen(str1) == 0) {
        return 0;
    }
    return (int)str1[0];
}