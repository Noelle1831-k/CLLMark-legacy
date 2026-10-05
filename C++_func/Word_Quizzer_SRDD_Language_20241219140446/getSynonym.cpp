string WordDatabase::getSynonym(const string& word, const string& language, int difficulty) {
    for (int i = 0; i < (int)synonyms.size(); i++) {
        if (synonyms[i].first == word) {
            return synonyms[i].second;
        }
    }
    return "unknown"; 
}