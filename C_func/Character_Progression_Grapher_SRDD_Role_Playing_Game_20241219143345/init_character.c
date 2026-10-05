void init_character(Character *character) {
    strncpy(character->name, "Unnamed", MAX_NAME_LENGTH);
    character->level = 1;
    memset(character->attributes, 0, sizeof(character->attributes));
    memset(character->skills, 0, sizeof(character->skills));
    for (int i = 0; i < MAX_EQUIPMENT; ++i) {
        strncpy(character->equipment[i], "None", MAX_NAME_LENGTH);
    }
}