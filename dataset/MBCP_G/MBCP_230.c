void replaceBlank(char *str, char chr) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            str[i] = chr;
        }
    }
}