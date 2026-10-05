void process_user_choice(int choice) {
    switch (choice) {
        case 1:
            take_grammar_lesson();
            break;
        case 2:
            start_vocabulary_quiz();
            break;
        case 3:
            practice_pronunciation();
            break;
        case 4:
            run_quiz();
            break;
        case 5:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}