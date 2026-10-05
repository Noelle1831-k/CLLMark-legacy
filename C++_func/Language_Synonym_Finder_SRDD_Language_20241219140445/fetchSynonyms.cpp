vector<string> DictionaryAPI::fetchSynonyms(const string& word) {
    vector<string> synonyms;
    simulateApiCall(word);  
    if (word == "happy") {
        synonyms.push_back("joyful");
        synonyms.push_back("content");
        synonyms.push_back("cheerful");
    } else if (word == "sad") {
        synonyms.push_back("unhappy");
        synonyms.push_back("downcast");
        synonyms.push_back("mournful");
    } else {
        cout << "No synonyms found for word: " << word << endl;
    }
    return synonyms;
}