void load_database_from_file(VerbDatabase* db, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("No existing database found. Starting fresh.\n");
        return;
    }
    fscanf(file, "%d", &db->num_verbs);
    for (int i = 0; i < db->num_verbs; i++) {
        Verb* verb = &db->verbs[i];
        fscanf(file, "%s %d", verb->root, &verb->num_conjugations);
        for (int j = 0; j < verb->num_conjugations; j++) {
            Conjugation* conj = &verb->conjugations[j];
            fscanf(file, "%s %s %s %s", conj->tense, conj->mood, conj->person, conj->conjugated_form);
        }
    }
    fclose(file);
    printf("Database loaded successfully.\n");
}