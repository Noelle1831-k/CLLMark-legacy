void free_character(Character *character) {
    if (character != NULL) {
        free(character->attributes);
        free(character->skills);
        free(character);
    }
}