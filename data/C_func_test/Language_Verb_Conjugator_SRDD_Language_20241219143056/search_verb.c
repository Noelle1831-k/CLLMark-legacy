Verb* search_verb(VerbDatabase* db, char* root) {
    for (int i = 0; i < db->num_verbs; i++) {
        if (strcmp(db->verbs[i].root, root) == 0) {
            return &db->verbs[i];
        }
    }
    return NULL;
}