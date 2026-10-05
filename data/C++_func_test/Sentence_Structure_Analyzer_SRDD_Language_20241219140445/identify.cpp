string POSIdentifier::identify(const string& word) {
    string lowerWord = toLowerCase(word);  
    if (posDictionary.find(lowerWord) != posDictionary.end()) {
        return posDictionary[lowerWord];
    }
    return "Unknown";  
}