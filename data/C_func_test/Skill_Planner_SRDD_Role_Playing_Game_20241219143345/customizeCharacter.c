void customizeCharacter(Character *character) {
    printf("Customizing character '%s'\n", character->name);
    printf("Enter new strength: ");
    character->strength = getValidatedInput(1, 100);
    printf("Enter new agility: ");
    character->agility = getValidatedInput(1, 100);
    printf("Enter new intelligence: ");
    character->intelligence = getValidatedInput(1, 100);
    printf("Character attributes updated successfully!\n");
}