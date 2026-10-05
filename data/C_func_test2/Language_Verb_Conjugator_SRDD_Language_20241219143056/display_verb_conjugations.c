void display_verb_conjugations(Verb* verb) {
    printf("\nConjugations for verb: %s\n", verb->root);
    for (int i = 0; i < verb->num_conjugations; i++) {
        Conjugation* conj = &verb->conjugations[i];
        printf("Tense: %s, Mood: %s, Person: %s -> %s\n", conj->tense, conj->mood, conj->person, conj->conjugated_form);
    }
}