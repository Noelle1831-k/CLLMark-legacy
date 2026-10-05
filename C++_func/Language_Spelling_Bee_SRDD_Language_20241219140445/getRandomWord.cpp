string WordDatabase::getRandomWord() {
    const vector<string>& currentWords = words[currentLanguage][currentDifficulty];
    int index = rand() % currentWords.size();
    return currentWords[index];
}