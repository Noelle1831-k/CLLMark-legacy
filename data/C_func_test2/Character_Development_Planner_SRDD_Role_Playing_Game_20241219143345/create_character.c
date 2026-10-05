Character* create_character() {
    Character *character = (Character*)malloc(sizeof(Character));
    if (character == NULL) {
        return NULL;
    }
    character->attributes = (int*)malloc(NUM_ATTRIBUTES * sizeof(int));
    character->skills = (int*)malloc(NUM_SKILLS * sizeof(int));
    if (character->attributes == NULL || character->skills == NULL) {
        free(character);
        return NULL;
    }
    memset(character->attributes, 0, NUM_ATTRIBUTES * sizeof(int));
    memset(character->skills, 0, NUM_SKILLS * sizeof(int));
    return character;
}