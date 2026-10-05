void gameLoop() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addPlayer();
                break;
            case 2:
                listItems();
                break;
            case 3:
                searchItem();
                break;
            case 4:
                initiateTrade();
                break;
            case 5:
                viewMessages();
                break;
            case 6:
                ratePlayer();
                break;
            case 0:
                printf("Exiting the game. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}