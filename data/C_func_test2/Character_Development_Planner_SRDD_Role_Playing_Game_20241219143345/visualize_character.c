void visualize_character(Character *character) {
    printf("Visualizing Character:\n");
    printf("Attributes:\n");
    for (int i = 0; i < NUM_ATTRIBUTES; i++) {
        printf("Attribute %d: %d\n", i + 1, character->attributes[i]);
    }
    printf("Skills:\n");
    for (int i = 0; i < NUM_SKILLS; i++) {
        printf("Skill %d: %d\n", i + 1, character->skills[i]);
    }
}