int main() {
    ExpenseManager expenseManager;
    Budget budget;
    ReceiptManager receiptManager;
    while (true) {
        displayMenu();
        handleUserInput(expenseManager, budget, receiptManager);
    }
    return 0;
}