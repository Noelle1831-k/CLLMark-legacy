void initialize_character(Character *character, const char *name, int strength, int agility, int intelligence) {
    strcpy(character->name, name);
    character->strength = strength;
    character->agility = agility;
    character->intelligence = intelligence;
}