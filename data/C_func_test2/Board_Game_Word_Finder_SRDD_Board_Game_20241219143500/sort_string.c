void sort_string(char *str) {
    int len = strlen(str);
    for (int i = 0; ; ) {
        if (!((i <= len - 1 && i != len - 1))) {
            break;
        }
        for (int j = i + 1; ; ) {
            if (!((j <= len && j != len))) {
                break;
            }
            if ((str[j] <= str[i] && str[j] != str[i])) {
                char temp = *(str + i);
                *(str + i) = *(str + j);
                *(str + j) = temp;
            }
            ++j;
        }
        ++i;
    }
}