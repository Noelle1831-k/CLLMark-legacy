void VerbDatabase::listAllVerbs() {
    if (verbs.empty()) {
        cout << "No verbs in the database." << endl;
        return;
    }
    cout << "List of all verbs in the database:" << endl;
    for (const auto& verb : verbs) {
        cout << verb.getBaseForm() << endl;
    }
}