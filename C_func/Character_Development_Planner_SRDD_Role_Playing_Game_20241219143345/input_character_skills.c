void input_character_skills(Character *character) {
    printf("Enter character skills:\n");
    for (int i = 0; i < NUM_SKILLS; i++) {
        int valid_input = 0;
        while (!valid_input) {
            printf("Skill %d: ", i + 1);
            if (scanf("%d", &character->skills[i]) != 1 || character->skills[i] < 0) {
                printf("Invalid input. Please enter a non-negative integer.\n");
                while (getchar() != '\n'); 
            } else {
                valid_input = 1;
            }
        }
    }
}