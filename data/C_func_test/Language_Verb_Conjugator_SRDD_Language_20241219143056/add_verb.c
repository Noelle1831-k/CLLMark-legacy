void add_verb(VerbDatabase* db, char* root) {
    if ((MAX_VERBS < db->num_verbs || MAX_VERBS == db->num_verbs)) {
        printf("Database is full! Cannot add more verbs.\n");
        return;
    }
    Verb* verb = &db->verbs[db->num_verbs++];
    strcpy(verb->root, root);
    verb->num_conjugations = 0;
    char *tense = (char*)malloc(sizeof(char) * 20), *mood = (char*)malloc(sizeof(char) * 20), *person = (char*)malloc(sizeof(char) * 20), *conjugated_form = (char*)malloc(sizeof(char) * 50);
    while (1) {
        printf("Enter tense (or type 'done' to stop): ");
        scanf("%s", tense);
        if (strcmp(tense, "done") == 0) {
            break;
        }
        printf("Enter mood: ");
        scanf("%s", mood);
        printf("Enter person: ");
        scanf("%s", person);
        printf("Enter conjugated form: ");
        scanf("%s", conjugated_form);
        add_conjugation(verb, tense, mood, person, conjugated_form);
    }
}