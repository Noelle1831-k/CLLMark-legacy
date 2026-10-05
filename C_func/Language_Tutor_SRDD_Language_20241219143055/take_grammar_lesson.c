void take_grammar_lesson() {
    int choice;
    printf("\nChoose a grammar lesson:\n");
    printf("1. Nouns\n");
    printf("2. Verbs\n");
    printf("3. Adjectives\n");
    printf("4. Adverbs\n");
    printf("5. Prepositions\n");
    printf("6. Back to Main Menu\n");
    printf("Your choice: ");
    choice = get_integer_input();
    switch (choice) {
        case 1:
            printf("Lesson on Nouns\n");
            break;
        case 2:
            printf("Lesson on Verbs\n");
            break;
        case 3:
            printf("Lesson on Adjectives\n");
            break;
        case 4:
            printf("Lesson on Adverbs\n");
            break;
        case 5:
            printf("Lesson on Prepositions\n");
            break;
        case 6:
            return;
        default:
            printf("Invalid choice. Returning to main menu.\n");
            return;
    }
    run_quiz();
}