void parse_sentence(char** tokens, char** tags, int num_tokens) {
    printf("\nParsing sentence structure:\n");
    int subject_found = 0, verb_found = 0, object_found = 0;
    for (int i = 0; i < num_tokens; i++) {
        if (strcmp(tags[i], "NOUN") == 0 && !subject_found) {
            printf("Subject: %s\n", tokens[i]);
            subject_found = 1;
        } else if (strcmp(tags[i], "VERB") == 0 && !verb_found) {
            printf("Verb: %s\n", tokens[i]);
            verb_found = 1;
        } else if (strcmp(tags[i], "NOUN") == 0 && !object_found && subject_found && verb_found) {
            printf("Object: %s\n", tokens[i]);
            object_found = 1;
        }
    }
    if (!subject_found || !verb_found) {
        printf("Warning: Sentence structure incomplete or ambiguous.\n");
    }
}