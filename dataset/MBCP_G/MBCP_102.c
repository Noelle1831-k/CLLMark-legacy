void snakeToCamel(const char *snake_case, char *camel_case) {
    int i = 0, j = 0;
    int convert_next = 1;
    while (snake_case[i] != '\0') {
        if (snake_case[i] == '_') {
            convert_next = 1;
        } else {
            if (convert_next) {
                camel_case[j++] = toupper(snake_case[i]);
                convert_next = 0;
            } else {
                camel_case[j++] = snake_case[i];
            }
        }
        i++;
    }
    camel_case[j] = '\0';
}