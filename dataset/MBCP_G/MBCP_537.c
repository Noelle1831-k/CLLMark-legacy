char* firstRepeatedWord(char* str1) {
    char* word;
    char* token;
    char* rest = str1;
    int found = 0;
    static char result[100];
    while ((word = strtok_r(rest, " ", &rest))) {
        token = rest;
        while ((token = strtok_r(token, " ", &token))) {
            if (strcmp(word, token) == 0) {
                strcpy(result, word);
                found = 1;
                break;
            }
        }
        if (found) break;
    }
    if (!found) strcpy(result, "None");
    return result;
}