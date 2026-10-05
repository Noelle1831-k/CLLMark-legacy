int main() {
    UserInterface ui;
    SynonymFinder finder;
    string word = ui.getUserInput();
    vector<string> synonyms = finder.findSynonyms(word);
    string definition = finder.getDefinition(word);
    vector<string> examples = finder.getExampleSentences(word);
    if (synonyms.empty()) {
        cout << "No synonyms found for the word \"" << word << "\"." << endl;
    }
    if (examples.empty()) {
        cout << "No example sentences found for the word \"" << word << "\"." << endl;
    }
    ui.displayResults(word, synonyms, definition, examples);
    return 0;
}