void saveTranslationsToFile(FILE *file) {
    for (int i = 0; i < dictionarySize; i++) {
        fprintf(file, "%s %s %s=%s\n",
                dictionary[i].srcLang,
                dictionary[i].destLang,
                dictionary[i].originalText,
                dictionary[i].translatedText);
    }
}