void collect_feedback() {
    int choice;
    while (1) {
        printf("\n--- Collect Feedback ---\n");
        printf("1. Add Feedback\n");
        printf("2. View Feedback\n");
        printf("3. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_feedback();
                break;
            case 2:
                view_feedback();
                break;
            case 3:
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}