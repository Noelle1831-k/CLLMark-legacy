int main() {
    User user;
    InputHandler inputHandler;
    BudgetAdvisor budgetAdvisor;
    Resource resource;
    Recommendation recommendation;
    cout << "Welcome to the Finance Assistant!" << endl;
    inputHandler.collectUserInput(user);
    recommendation.generateRecommendations(user, budgetAdvisor);
    resource.showEducationalResources();
    return 0;
}