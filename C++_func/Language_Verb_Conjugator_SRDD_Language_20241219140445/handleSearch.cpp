void ConjugatorApp::handleSearch() {
    cout << "Enter the base form of the verb: ";
    string baseForm;
    cin >> baseForm;
    Verb* verb = database.searchVerb(baseForm);
    if (verb) {
        cout << "Conjugations for " << baseForm << ":" << endl;
        verb->displayConjugations();
    } else {
        cout << "Verb not found." << endl;
    }
}