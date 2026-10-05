void FinancialDecision::diversifyInvestment(Company &company, double amount) {
    company.addInvestment(amount * 0.5);
    cout << "Diversified investment made." << endl;
}