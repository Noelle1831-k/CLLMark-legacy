void executeChoice(int choice) {
    switch (choice) {
        case 1:
            inputIncome();
            break;
        case 2:
            inputExpense();
            break;
        case 3:
            setSavingsTarget();
            break;
        case 4:
            displaySavingsProgress();
            break;
        case 5:
            generateReport();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}