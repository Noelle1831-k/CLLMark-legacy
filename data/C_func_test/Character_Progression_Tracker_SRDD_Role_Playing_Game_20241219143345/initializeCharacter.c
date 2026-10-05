void initializeCharacter(Character *character) {
    strcpy(character->name, "Unnamed Hero");
    character->level = 1;
    character->strength = 10;
    character->agility = 10;
    character->intelligence = 10;
    character->skillCount = 0;
    character->equipmentCount = 0;
}