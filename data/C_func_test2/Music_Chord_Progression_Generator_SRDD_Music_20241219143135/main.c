int main() {
    char key[10];
    char mood[20];
    ChordProgression progression;
    printf("Welcome to the Music Chord Progression Generator!\n");
    printf("Enter a musical key (e.g., C, G, Am, F#m): ");
    scanf("%s", key);
    if (!validate_key(key)) {
        printf("Invalid key entered. Exiting program.\n");
        return 1;
    }
    printf("Select a mood/style (happy, sad, jazz): ");
    scanf("%s", mood);
    if (!validate_mood(mood)) {
        printf("Invalid mood entered. Exiting program.\n");
        return 1;
    }
    progression = generate_chord_progression(key, mood);
    if (progression.size == 0) {
        printf("No chord progression could be generated. Exiting program.\n");
        return 1;
    }
    printf("Generated Chord Progression:\n");
    print_chord_progression(progression);
    printf("Would you like to save this progression? (y/n): ");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        char filename[50];
        printf("Enter filename to save the progression: ");
        scanf("%s", filename);
        if (save_chord_progression(progression, filename)) {
            printf("Chord progression saved successfully to %s.\n", filename);
        } else {
            printf("Failed to save chord progression.\n");
        }
    }
    free_chord_progression(progression);
    return 0;
}