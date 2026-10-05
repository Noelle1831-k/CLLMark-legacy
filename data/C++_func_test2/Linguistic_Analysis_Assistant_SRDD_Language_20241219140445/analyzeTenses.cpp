void VerbTenses::analyzeTenses(const string& text) {
    vector<string> words = Utility::splitText(text, ' ');
    for (size_t i = 0; i < words.size(); i++) {
        string word = Utility::toLowerCase(words[i]);
        string tense = getVerbTense(word);
        cout << "Word " << i + 1 << ": " << words[i] << " - Verb Tense: " << tense << endl;
    }
}