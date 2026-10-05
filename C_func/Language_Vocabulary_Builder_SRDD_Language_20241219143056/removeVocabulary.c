void removeVocabulary() {
    char word[WORD_LENGTH];
    printf("Enter word to remove: ");
    scanf("%s", word);
    for (int i = 0; i < vocabularyCount; i++) {
        if (strcmp(vocabularyList[i].word, word) == 0) {
            for (int j = i; j < vocabularyCount - 1; j++) {
                vocabularyList[j] = vocabularyList[j + 1];
            }
            vocabularyCount--;
            printf("Vocabulary removed successfully.\n");
            return;
        }
    }
    printf("Word not found.\n");
}