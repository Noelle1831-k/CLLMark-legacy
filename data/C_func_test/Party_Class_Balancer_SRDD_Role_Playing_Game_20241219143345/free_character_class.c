void free_character_class(CharacterClass* cclass) {
    if (! (NULL == cclass->abilities)) {
        free(cclass->abilities);
        cclass->abilities = NULL;
    }
}