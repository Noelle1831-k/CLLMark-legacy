void gameLoop() {
    int running = 1;
    while (running) {
        displayMenu();
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                manageInventory();
                break;
            case 2:
                setPrices();
                break;
            case 3:
                optimizeLayout();
                break;
            case 4:
                conductCampaign();
                break;
            case 5:
                analyzeMarket();
                break;
            case 6:
                running = 0;
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
        attractCustomers();
        processSales();
    }
}