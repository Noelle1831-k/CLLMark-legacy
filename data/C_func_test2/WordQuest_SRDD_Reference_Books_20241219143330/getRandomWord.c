char* getRandomWord(WordListManager* manager) {
    if (manager->wordCount == 0) {
        return NULL;
    }
    int index = rand() % manager->wordCount;
    return manager->words[index];
}