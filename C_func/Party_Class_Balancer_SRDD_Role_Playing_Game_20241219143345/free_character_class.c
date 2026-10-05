void free_character_class(CharacterClass* cclass) {
    if (cclass->abilities != NULL) {
        free(cclass->abilities);
        cclass->abilities = NULL;
    }
}