string WordDatabase::getRandomWord(const string& language, int difficulty) {
    return words[getRandomNumber(0, words.size() - 1)];
}