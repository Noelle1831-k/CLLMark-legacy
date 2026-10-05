void numPosition(const char *text) {
    int i = 0;
    while (text[i] != '\0') {
        if (isdigit(text[i])) {
            printf("%d\n", i);
            return;
        }
        i++;
    }
}