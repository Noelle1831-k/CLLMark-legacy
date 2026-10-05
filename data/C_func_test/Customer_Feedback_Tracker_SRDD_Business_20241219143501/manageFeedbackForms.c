void manageFeedbackForms() {
    int choice;
    do {
        printf("\n1. Create a New Feedback Form\n");
        printf("2. Edit an Existing Feedback Form\n");
        printf("3. Delete a Feedback Form\n");
        printf("4. View Feedback Forms\n");
        printf("5. Go Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createForm();
                break;
            case 2:
                editForm();
                break;
            case 3:
                deleteForm();
                break;
            case 4:
                viewForms();
                break;
            case 5:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}