void addTranslation(const char *entry) {
    if (dictionarySize >= MAX_DICTIONARY_SIZE) {
        printf("Error: Dictionary is full.\n");
        return;
    }
    sscanf(entry, "%19s %19s %255[^=]=%255[^\n]",
           dictionary[dictionarySize].srcLang,
           dictionary[dictionarySize].destLang,
           dictionary[dictionarySize].originalText,
           dictionary[dictionarySize].translatedText);
    dictionarySize++;
}