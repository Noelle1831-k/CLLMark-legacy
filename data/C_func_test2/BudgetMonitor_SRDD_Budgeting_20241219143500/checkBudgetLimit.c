void checkBudgetLimit() {
    float balance = calculateBalance();
    if (balance < 0) {
        sendNotification();
    }
}