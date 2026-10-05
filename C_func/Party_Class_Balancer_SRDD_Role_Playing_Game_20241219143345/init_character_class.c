void init_character_class(CharacterClass* cclass, const char* name) {
    strncpy(cclass->name, name, sizeof(cclass->name) - 1);
    cclass->abilities = NULL;
    cclass->num_abilities = 0;
}