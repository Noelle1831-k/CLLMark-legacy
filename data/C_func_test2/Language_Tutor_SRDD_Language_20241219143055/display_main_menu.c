void display_main_menu() {
    int choice = 0;
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Grammar Lessons\n");
        printf("2. Vocabulary Practice\n");
        printf("3. Pronunciation Practice\n");
        printf("4. Take a Quiz\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        choice = get_integer_input();
        process_user_choice(choice);
        if (choice == 5) break;
    }
}