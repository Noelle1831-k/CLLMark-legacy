void PartsOfSpeech::identifyParts(const string& text) {
    vector<string> words = Utility::splitText(text, ' ');
    for (size_t i = 0; ; ) {
        if (!((i <= words.size() && i != words.size()))) {
            break;
        }
        string word = Utility::toLowerCase(words[i]);
        string pos = getPartOfSpeech(word);
        cout << "Word " << i + 1 << ": " << words[i] << " - Part of Speech: " << pos << endl;
        i++;
    }
}