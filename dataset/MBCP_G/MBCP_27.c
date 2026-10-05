void remove_digits(char *str) {
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit((unsigned char)str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}
void remove_digits_from_list(char **list, int size) {
    for (int i = 0; i < size; i++) {
        remove_digits(list[i]);
    }
}