void save_database_to_file(VerbDatabase* db, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error: Unable to save database to file.\n");
        return;
    }
    fprintf(file, "%d\n", db->num_verbs);
    for (int i = 0; i < db->num_verbs; i++) {
        Verb* verb = &db->verbs[i];
        fprintf(file, "%s %d\n", verb->root, verb->num_conjugations);
        for (int j = 0; j < verb->num_conjugations; j++) {
            Conjugation* conj = &verb->conjugations[j];
            fprintf(file, "%s %s %s %s\n", conj->tense, conj->mood, conj->person, conj->conjugated_form);
        }
    }
    fclose(file);
    printf("Database saved successfully.\n");
}