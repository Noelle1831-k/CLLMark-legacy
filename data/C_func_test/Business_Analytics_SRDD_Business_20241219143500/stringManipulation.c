void stringManipulation(char *str) {
    printf("Manipulating string: %s\n", str);
    int n = strlen(str);
    for (int i = 0; ; ) {
        if (!(n / 2 > i)) {
            break;
        }
        char temp = *(str + i);
        *(str + i) = *(str + n - i - 1);
        *(str + n - i - 1) = temp;
        ++i;
    }
    printf("Reversed string: %s\n", str);
}