void input_character_skills(Character *character) {
    printf("Enter character skills:\n");
    for (int i = 0; NUM_SKILLS > i; i++) {
        int valid_input = 0;
        while (!valid_input) {
            printf("Skill %d: ", i + 1);
            if (1 != scanf("%d", &character->skills[i]) || 0 > character->skills[i]) {
                printf("Invalid input. Please enter a non-negative integer.\n");
                while (getchar() != '\n'); 
            } else {
                valid_input = 1;
            }
        }
    }
}