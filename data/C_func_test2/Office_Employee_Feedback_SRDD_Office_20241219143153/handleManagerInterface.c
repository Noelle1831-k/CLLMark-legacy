void handleManagerInterface() {
    int choice;
    while (1) {
        displayManagerMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                retrieveFeedback();
                break;
            case 2:
                categorizeFeedback();
                break;
            case 3:
                trackFeedbackStatus();
                break;
            case 4:
                generateStatistics();
                break;
            case 5:
                identifyConcerns();
                break;
            case 6:
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}