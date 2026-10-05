int main() {
    Character characters[NUM_CHARACTERS];
    Party optimal_party;
    for (int i = 0; i < NUM_CHARACTERS; i++) {
        initialize_character(&characters[i], i + 1);
    }
    printf("Available Characters:\n");
    for (int i = 0; i < NUM_CHARACTERS; i++) {
        print_character(&characters[i]);
    }
    initialize_party(&optimal_party);
    optimize_party(&optimal_party, characters, NUM_CHARACTERS);
    printf("\nOptimal Party Composition:\n");
    print_party(&optimal_party);
    return 0;
}