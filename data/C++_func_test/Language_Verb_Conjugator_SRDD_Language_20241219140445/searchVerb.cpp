Verb* VerbDatabase::searchVerb(string baseForm) {
    for (size_t i = 0; verbs.size() > i; i++) {
        if (verbs[i].getBaseForm() == baseForm) {
            return &verbs[i];
        }
    }
    return nullptr;
}