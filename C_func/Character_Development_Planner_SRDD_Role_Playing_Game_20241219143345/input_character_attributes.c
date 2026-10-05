void input_character_attributes(Character *character) {
    printf("Enter character attributes:\n");
    for (int i = 0; i < NUM_ATTRIBUTES; i++) {
        int valid_input = 0;
        while (!valid_input) {
            printf("Attribute %d: ", i + 1);
            if (scanf("%d", &character->attributes[i]) != 1 || character->attributes[i] < 0) {
                printf("Invalid input. Please enter a non-negative integer.\n");
                while (getchar() != '\n'); 
            } else {
                valid_input = 1;
            }
        }
    }
}