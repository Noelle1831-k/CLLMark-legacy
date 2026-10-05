void replace_hoshino(char *text) {
    char *pos, temp[1005];
    int index = 0;
    int len;
    char target[] = "Hoshino";
    char replacement[] = "Hoshina";
    len = strlen(target);
    while ((pos = strstr(text, target)) != NULL) {
        strcpy(temp, text);
        index = pos - text;
        text[index] = '\0';
        strcat(text, replacement);
        strcat(text, temp + index + len);
    }
}