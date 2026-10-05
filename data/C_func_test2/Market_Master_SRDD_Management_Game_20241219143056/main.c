int main() {
    srand(time(NULL));
    Portfolio portfolio = initializePortfolio();
    Market market = initializeMarket();
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayPortfolio(&portfolio);
                break;
            case 2:
                buyStocks(&portfolio, &market);
                break;
            case 3:
                sellStocks(&portfolio, &market);
                break;
            case 4:
                analyzeMarket(&market);
                break;
            case 5:
                displayMarketNews(&market);
                break;
            case 6:
                printf("Exiting the game. Goodbye!\n");
                freePortfolio(&portfolio);
                freeMarket(&market);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        updateMarket(&market);  
    }
}