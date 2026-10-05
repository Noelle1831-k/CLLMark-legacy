void to_lowercase(char *str) {
    for (; *str; str++) {
        *str = tolower(*str);
    }
}