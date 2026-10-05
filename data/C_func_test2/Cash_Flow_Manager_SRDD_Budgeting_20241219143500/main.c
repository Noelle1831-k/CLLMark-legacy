int main() {
    printf("Welcome to CashFlowManager!\n");
    initializeTransactions();
    handleUserInput();
    cleanupTransactions();
    printf("Thank you for using CashFlowManager. Goodbye!\n");
    return 0;
}