Character createCharacter() {
    Character character;
    printf("Enter character name: ");
    scanf("%s", character.name);
    printf("Enter character class (e.g., Warrior, Mage, Healer): ");
    scanf("%s", character.class);
    while (1) {
        printf("Enter character strength (1-100): ");
        scanf("%d", &character.strength);
        if (character.strength >= 1 && character.strength <= 100) break;
        printf("Invalid input. Strength must be between 1 and 100.\n");
    }
    while (1) {
        printf("Enter character intelligence (1-100): ");
        scanf("%d", &character.intelligence);
        if (character.intelligence >= 1 && character.intelligence <= 100) break;
        printf("Invalid input. Intelligence must be between 1 and 100.\n");
    }
    while (1) {
        printf("Enter character agility (1-100): ");
        scanf("%d", &character.agility);
        if (character.agility >= 1 && character.agility <= 100) break;
        printf("Invalid input. Agility must be between 1 and 100.\n");
    }
    printf("Enter character role (e.g., Tank, DPS, Support): ");
    scanf("%s", character.role);
    return character;
}