void TextProcessor::tokenize(const string& lyrics) {
    stringstream ss(lyrics);
    string word;
    while (ss >> word) {
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
        transform(word.begin(), word.end(), word.begin(), ::tolower);  
        words.push_back(word);
    }
}