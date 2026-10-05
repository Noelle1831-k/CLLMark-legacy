void handle_user_input() {
    char input[MAX_INPUT_LENGTH];
    int option = 0;
    while (1) {
        printf("Enter your choice (1-3): ");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        option = atoi(input);
        if (option == 1) {
            Skill skill = create_skill_from_user_input();
            int difficulty = analyze_skill_difficulty(skill);
            printf("\nSkill Difficulty Rating: %d\n\n", difficulty);
        } else if (option == 2) {
            Skill skill = create_skill_from_user_input();
            print_skill_details(skill);
        } else if (option == 3) {
            printf("Exiting application. Goodbye!\n");
            break;
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }
}