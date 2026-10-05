void QuestGuide::listHints() const {
    if (hints.empty()) {
        cout << "No hints available.\n";
        return;
    }
    for (map<string, string>::const_iterator it = hints.begin(); it != hints.end(); ++it) {
        cout << "Quest: " << it->first << "\nHint: " << it->second << endl;
    }
}