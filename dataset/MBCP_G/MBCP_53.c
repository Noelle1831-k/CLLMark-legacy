const char* checkEquality(const char* str) {
    int length = strlen(str);
    if (length > 0 && str[0] == str[length - 1]) {
        return "Equal";
    } else {
        return "Not Equal";
    }
}