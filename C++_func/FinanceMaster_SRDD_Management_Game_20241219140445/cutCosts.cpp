void FinancialDecision::cutCosts(Company &company, double amount) {
    company.addExpense(-amount);
}