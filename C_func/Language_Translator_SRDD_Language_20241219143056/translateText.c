char *translateText(const char *text, const char *srcLang, const char *destLang) {
    if (!text || !srcLang || !destLang) {
        return NULL;
    }
    for (int i = 0; i < dictionarySize; i++) {
        if (strcmp(dictionary[i].srcLang, srcLang) == 0 &&
            strcmp(dictionary[i].destLang, destLang) == 0 &&
            strcmp(dictionary[i].originalText, text) == 0) {
            char *translation = (char *)malloc(strlen(dictionary[i].translatedText) + 1);
            if (!translation) {
                perror("Memory allocation failed");
                return NULL;
            }
            strcpy(translation, dictionary[i].translatedText);
            return translation;
        }
    }
    printf("Error: Translation not found in dictionary.\n");
    return NULL;
}