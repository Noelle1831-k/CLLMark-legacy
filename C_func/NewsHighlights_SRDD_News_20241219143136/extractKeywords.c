char* extractKeywords(char* article, char* keywords[], int keywordCount) {
    static char extractedSentence[256];
    char* sentence = strtok(article, ".");
    while (sentence != NULL) {
        for (int i = 0; i < keywordCount; i++) {
            if (strstr(sentence, keywords[i]) != NULL) {
                strncpy(extractedSentence, sentence, 255);
                extractedSentence[255] = '\0';
                return extractedSentence;
            }
        }
        sentence = strtok(NULL, ".");
    }
    return NULL;
}