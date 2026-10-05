char* capitalizeFirstLastLetters(char* str) {
    int len = strlen(str);
    if (len > 0) {
        str[0] = toupper(str[0]);
        if (len > 1) {
            str[len - 1] = toupper(str[len - 1]);
        }
    }
    return str;
}