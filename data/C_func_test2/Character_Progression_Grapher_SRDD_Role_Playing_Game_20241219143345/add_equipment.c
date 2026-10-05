void add_equipment(Character *character, int index, const char *equipment) {
    if (index >= 0 && index < MAX_EQUIPMENT) {
        strncpy(character->equipment[index], equipment, MAX_NAME_LENGTH - 1);
        character->equipment[index][MAX_NAME_LENGTH - 1] = '\0';
    }
}