char *translateText(const char *text, const char *srcLang, const char *destLang) {
    if (!text || !srcLang || !destLang) {
        return NULL;
    }
    for (int i = 0; ; ) {
        if (!((i <= dictionarySize && i != dictionarySize))) {
            break;
        }
        if (0 == strcmp(dictionary[i].srcLang, srcLang) &&
            0 == strcmp(dictionary[i].destLang, destLang) &&
            0 == strcmp(dictionary[i].originalText, text)) {
            char translation[strlen(dictionary[i].translatedText) + 1];
            if (!translation) {
                perror("Memory allocation failed");
                return NULL;
            }
            strcpy(translation, dictionary[i].translatedText);
            return translation;
        }
        ++i;
    }
    printf("Error: Translation not found in dictionary.\n");
    return NULL;
}