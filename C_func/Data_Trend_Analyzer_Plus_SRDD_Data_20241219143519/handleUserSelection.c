void handleUserSelection() {
    int choice;
    if (scanf("%d", &choice) != 1) {
        printError("Invalid input. Please enter a number.");
        while (getchar() != '\n');  
        return;
    }
    switch (choice) {
        case 1:
            importData();
            break;
        case 2:
            analyzeTrends();
            break;
        case 3:
            buildPredictiveModel();
            break;
        case 4:
            performHypothesisTest();
            break;
        case 5:
            forecastTrends();
            break;
        case 6:
            printf("Exiting the application. Goodbye!\n");
            exit(0);
        default:
            printError("Invalid choice. Please try again.");
    }
}