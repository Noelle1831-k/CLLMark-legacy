void process_user_input(int choice) {
    switch (choice) {
        case 1:
            handle_goals();
            break;
        case 2:
            handle_study();
            break;
        case 3:
            handle_vocabulary();
            break;
        case 4:
            handle_grammar();
            break;
        case 5:
            display_dashboard();
            break;
        case 6:
            handle_reminders();
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
    }
}