int main() {
    User user;
    Budget budget;
    FinancialAdvice advice;
    Transaction transaction;
    user.setUserDetails();
    budget.calculateBudget();
    advice.generateAdvice();
    transaction.addTransaction();
    advice.displayAdvice();
    transaction.listTransactions();
    return 0;
}