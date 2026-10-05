void UserInterface::displayResults(const string& word, const vector<string>& synonyms, const string& definition, const vector<string>& examples) {
    cout << "\nResults for the word: " << word << endl;
    cout << "Synonyms: ";
    if (synonyms.empty()) {
        cout << "No synonyms found." << endl;
    } else {
        for (size_t i = 0; i < synonyms.size(); ++i) {
            cout << synonyms[i];
            if (i < synonyms.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
    cout << "Definition: " << definition << endl;
    cout << "Example Sentences: " << endl;
    if (examples.empty()) {
        cout << "No examples found." << endl;
    } else {
        for (const auto& example : examples) {
            cout << "- " << example << endl;
        }
    }
}