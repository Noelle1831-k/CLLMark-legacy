void createCharacter(Character *character) {
    printf("Enter character name: ");
    scanf("%s", character->name);
    printf("Character '%s' created successfully!\n", character->name);
}