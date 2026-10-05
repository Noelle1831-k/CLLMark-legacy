void VerbDatabase::listAllVerbs() {
    if (verbs.empty()) {
        printf("No verbs in the database.\n");
        return;
    }
    printf("List of all verbs in the database:\n");
    for (const auto& verb : verbs) {
        cout << verb.getBaseForm() << endl;
    }
}