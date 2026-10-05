void displayCharacter(const Character *character) {
    printf("\n=== Character Details ===\n");
    printf("Name: %s\n", character->name);
    printf("Strength: %d\n", character->strength);
    printf("Agility: %d\n", character->agility);
    printf("Intelligence: %d\n", character->intelligence);
    printf("Skills: ");
    if (character->skillCount == 0) {
        printf("None\n");
    } else {
        for (int i = 0; i < character->skillCount; i++) {
            printf("%s ", character->skills[i]);
        }
        printf("\n");
    }
    printf("=========================\n");
}