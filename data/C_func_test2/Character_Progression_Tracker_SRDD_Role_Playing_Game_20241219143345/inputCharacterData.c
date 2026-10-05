void inputCharacterData(Character *character) {
    printf("Enter character name: ");
    scanf("%s", character->name);
    printf("Enter character level: ");
    scanf("%d", &character->level);
    printf("Enter strength: ");
    scanf("%d", &character->strength);
    printf("Enter agility: ");
    scanf("%d", &character->agility);
    printf("Enter intelligence: ");
    scanf("%d", &character->intelligence);
}