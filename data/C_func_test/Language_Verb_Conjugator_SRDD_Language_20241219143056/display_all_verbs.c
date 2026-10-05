void display_all_verbs(VerbDatabase* db) {
    if (db->num_verbs == 0) {
        printf("No verbs in the database.\n");
        return;
    }
    printf("\n--- All Verbs in the Database ---\n");
    for (int i = 0; i < db->num_verbs; i++) {
        printf("%d. %s\n", i + 1, db->verbs[i].root);
    }
}