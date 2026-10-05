void addVocabulary() {
    if (vocabularyCount >= MAX_VOCABULARY) {
        printf("Vocabulary list is full.\n");
        return;
    }
    printf("Enter word: ");
    scanf("%s", vocabularyList[vocabularyCount].word);
    printf("Enter meaning: ");
    scanf("%s", vocabularyList[vocabularyCount].meaning);
    vocabularyCount++;
    printf("Vocabulary added successfully.\n");
}