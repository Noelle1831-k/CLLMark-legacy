void toUpperCase(char* str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}