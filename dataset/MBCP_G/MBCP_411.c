char* snakeToCamel(const char* snake_case) {
    int length = strlen(snake_case);
    char* camel_case = (char*)malloc(length + 1);
    if (camel_case == NULL) {
        return NULL;  
    }
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (snake_case[i] == '_') {
            if (i + 1 < length) {
                camel_case[j] = toupper(snake_case[i + 1]);
                i++;
            }
        } else {
            camel_case[j] = i == 0 ? toupper(snake_case[i]) : snake_case[i];
        }
        j++;
    }
    camel_case[j] = '\0';
    return camel_case;
}
