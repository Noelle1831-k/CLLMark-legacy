char* removeSpaces(const char* text) {
    char* result = (char*)malloc(strlen(text) + 1);
    if (!result) {
        return NULL; 
    }
    int i = 0, j = 0;
    int inSpaceSequence = 0;
    while (text[i] != '\0') {
        if (text[i] != ' ') {
            result[j++] = text[i];
            inSpaceSequence = 0;
        } else if (!inSpaceSequence) {
            result[j++] = ' ';
            inSpaceSequence = 1;
        }
        i++;
    }
    if (j > 0 && result[j - 1] == ' ') {
        j--; 
    }
    result[j] = '\0';
    return result;
}