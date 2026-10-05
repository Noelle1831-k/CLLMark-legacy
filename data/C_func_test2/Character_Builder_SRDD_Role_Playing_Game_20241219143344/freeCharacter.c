void freeCharacter(Character *character) {
    if (character) {
        free(character->race);
        free(character->class);
        free(character->abilities);
        free(character->equipment);
        free(character);
    }
}