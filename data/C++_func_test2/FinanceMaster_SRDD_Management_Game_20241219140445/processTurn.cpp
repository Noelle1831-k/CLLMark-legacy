void Game::processTurn() {
    market.analyzeTrends();
    double impact = market.getMarketImpact();
    company.addRevenue(1000 * impact);
    company.addExpense(500);
    decision.makeInvestment(company, 200);
    company.updateBalance();
    company.displayStatus();
    market.displayMarketTrends();
    displayMenu();
}