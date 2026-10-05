void handleUserInput(int *running) {
    int choice = getInput();
    switch (choice) {
        case 1:
            addIncome();
            break;
        case 2:
            addExpense();
            break;
        case 3:
            generateReport();
            break;
        case 4:
            setReminder();
            break;
        case 5:
            *running = 0;
            break;
        default:
            invalidOptionMessage();
            break;
    }
}