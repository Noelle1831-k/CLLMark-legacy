void handle_user_selection(int selection) {
    switch (selection) {
        case 1:
            input_expense();
            break;
        case 2:
            set_budget();
            break;
        case 3:
            display_notifications();
            break;
        case 4:
            visualize_expenses();
            break;
        case 5:
            generate_report();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}