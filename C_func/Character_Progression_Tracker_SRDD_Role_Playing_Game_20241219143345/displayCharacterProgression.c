void displayCharacterProgression(const Character *character) {
    printf("\nCharacter Progression for %s\n", character->name);
    printf("Level: %d\n", character->level);
    printf("Strength: %d\n", character->strength);
    printf("Agility: %d\n", character->agility);
    printf("Intelligence: %d\n", character->intelligence);
    printf("Skills:\n");
    for (int i = 0; i < character->skillCount; i++) {
        printf("  %s (Level %d)\n", character->skills[i].name, character->skills[i].level);
    }
    printf("Equipment:\n");
    for (int i = 0; i < character->equipmentCount; i++) {
        printf("  %s (Bonus %d)\n", character->equipment[i].name, character->equipment[i].bonus);
    }
}