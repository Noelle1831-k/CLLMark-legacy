void removeLowercase(char *str) {
    int i, j = 0;
    int len = strlen(str);
    for(i = 0; i < len; i++) {
        if(!islower(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}