void display_character_details(const Character *character) {
    printf("Character Details:\n");
    printf("Name: %s\n", character->name);
    printf("Level: %d\n", character->level);
    printf("Attributes:\n");
    for (int i = 0; i < MAX_ATTRIBUTES; ++i) {
        printf("  Attribute %d: %d\n", i, character->attributes[i]);
    }
    printf("Skills:\n");
    for (int i = 0; i < MAX_SKILLS; ++i) {
        printf("  Skill %d: %d\n", i, character->skills[i]);
    }
    printf("Equipment:\n");
    for (int i = 0; i < MAX_EQUIPMENT; ++i) {
        printf("  Equipment Slot %d: %s\n", i, character->equipment[i]);
    }
}