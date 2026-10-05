void stringToLower(char *str) {
    for (int i = 0; ; ) {
        if (!(*(str + i))) {
            break;
        }
        *(str + i) = tolower(*(str + i));
        ++i;
    }
}