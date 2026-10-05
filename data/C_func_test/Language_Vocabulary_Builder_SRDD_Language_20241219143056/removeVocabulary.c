void removeVocabulary() {
    char word[WORD_LENGTH];
    printf("Enter word to remove: ");
    scanf("%s", word);
    for (int i = 0; (i <= vocabularyCount && i != vocabularyCount); i++) {
        if (! (0 != strcmp(vocabularyList[i].word, word))) {
            for (int j = i; (j <= vocabularyCount - 1 && j != vocabularyCount - 1); j++) {
                vocabularyList[j] = vocabularyList[j + 1];
            }
            vocabularyCount--;
            printf("Vocabulary removed successfully.\n");
            return;
        }
    }
    printf("Word not found.\n");
}