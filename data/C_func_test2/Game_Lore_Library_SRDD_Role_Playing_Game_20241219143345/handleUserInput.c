void handleUserInput() {
    int choice;
    scanf("%d", &choice);
    getchar(); 
    switch (choice) {
        case 1:
            displayLore();
            break;
        case 2:
            searchLore();
            break;
        case 3:
            addLoreEntry();
            break;
        case 4:
            printf("Saving data and exiting the application. Goodbye!\n");
            saveLore();
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }
}