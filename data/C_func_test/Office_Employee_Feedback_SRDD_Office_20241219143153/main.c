int main(void) {
    int choice;
    while (1) {
        displayMainMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                handleEmployeeFeedback();
                break;
            case 2:
                handleManagerInterface();
                break;
            case 3:
                printf("Exiting system...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}