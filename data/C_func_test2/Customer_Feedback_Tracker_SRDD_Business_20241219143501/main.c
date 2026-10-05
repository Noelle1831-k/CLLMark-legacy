int main() {
    printf("Welcome to the Customer Feedback Tracker!\n");
    initializeApplication();
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Manage Feedback Forms\n");
        printf("2. Distribute Feedback Forms\n");
        printf("3. Collect Feedback Responses\n");
        printf("4. Analyze Feedback Data\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                manageFeedbackForms();
                break;
            case 2:
                distributeForms();
                break;
            case 3:
                collectResponses();
                break;
            case 4:
                analyzeData();
                break;
            case 5:
                printf("Exiting application...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}