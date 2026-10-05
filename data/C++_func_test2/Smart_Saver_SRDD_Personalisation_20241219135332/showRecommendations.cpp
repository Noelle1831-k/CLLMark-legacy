void UserInterface::showRecommendations(const RecommendationEngine& recommendationEngine, const ExpenseManager& expenseManager) const {
    recommendationEngine.generateRecommendations(expenseManager);
}