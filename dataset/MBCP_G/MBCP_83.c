char getChar(const char *strr) {
    int sum = 0;
    for (size_t i = 0; i < strlen(strr); ++i) {
        sum += strr[i];
    }
    return (char)(sum % 256);
}