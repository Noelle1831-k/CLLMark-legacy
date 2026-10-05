void mainMenu() {
    int choice;
    do {
        printf("\nMain Menu:\n");
        printf("1. Add Book Manually\n");
        printf("2. Scan Barcode to Add Book\n");
        printf("3. List All Books\n");
        printf("4. Search for a Book\n");
        printf("5. Remove a Book\n");
        printf("6. Update Reading Progress\n");
        printf("7. Get Recommendations\n");
        printf("8. Track Reading Progress\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        handleUserChoice(choice);
    } while (choice != 9);
}