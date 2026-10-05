char* removeDuplicate(char* str) {
    char* result = (char*)malloc(strlen(str) + 1);
    char* word = strtok(str, " ");
    char* temp;
    strcpy(result, "");
    while (word != NULL) {
        if (!strstr(result, word)) {
            strcat(result, word);
            strcat(result, " ");
        }
        word = strtok(NULL, " ");
    }
    if ((temp = strrchr(result, ' ')) != NULL) {
        *temp = '\0';
    }
    return result;
}