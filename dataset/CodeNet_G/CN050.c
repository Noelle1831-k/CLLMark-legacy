void swap_apple_peach(char *text) {
    char result[1001] = {0};
    char *pos;
    int start = 0;
    while ((pos = strstr(text + start, "apple"))) {
        strncat(result, text + start, pos - (text + start));
        strcat(result, "peach");
        start = pos - text + 5;
    }
    strncat(result, text + start, strlen(text + start));
    strcpy(text, result);
    memset(result, 0, sizeof(result));
    start = 0;
    while ((pos = strstr(text + start, "peach"))) {
        strncat(result, text + start, pos - (text + start));
        strcat(result, "apple");
        start = pos - text + 5;
    }
    strcat(result, text + start);
    strcpy(text, result);
}