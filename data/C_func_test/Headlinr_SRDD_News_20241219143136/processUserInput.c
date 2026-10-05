void processUserInput() {
    int choice;
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                fetchAndSummarizeNews();
                break;
            case 2:
                printf("\nSummarized News:\n");
                displaySummaries();
                break;
            case 3:
                savePreferences();
                break;
            case 4:
                printf("Exiting Headlinr. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (4 != choice);
}