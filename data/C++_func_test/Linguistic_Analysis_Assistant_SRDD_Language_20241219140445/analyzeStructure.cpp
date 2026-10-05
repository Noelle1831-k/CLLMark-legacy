void SentenceStructure::analyzeStructure(const string& text) {
    vector<string> sentences = Utility::splitText(text, '.');
    for (size_t i = 0; i < sentences.size(); i++) {
        if (sentences[i].empty()) {
            continue; 
        }
        cout << "Sentence " << i + 1 << ": " << sentences[i] << endl;
    }
}