char *process_text(char *text) {
    int len = strlen(text);
    char *processed_text = (char *)malloc(len + 1);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (isalpha(text[i]) || isspace(text[i])) {
            processed_text[j++] = tolower(text[i]);
        }
    }
    processed_text[j] = '\0';  
    return processed_text;
}